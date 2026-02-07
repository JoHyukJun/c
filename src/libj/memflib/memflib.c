#include "memflib.h"

int print_memflib()
{
    printf("MEMFLIB\n");
    return 0;
}

// 공유 메모리 생성 및 초기화
memf_handle_t* memf_create(const char *name, size_t data_size)
{
    if (!name || data_size == 0) {
        fprintf(stderr, "Invalid parameters\n");
        return NULL;
    }

    memf_handle_t *handle = (memf_handle_t *)malloc(sizeof(memf_handle_t));
    if (!handle) {
        perror("malloc failed");
        return NULL;
    }

    // 전체 크기 계산: 헤더 + 인덱스 + 데이터
    handle->total_size = sizeof(memf_shm_t) + data_size;

    // 공유 메모리 생성
    handle->fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (handle->fd == -1) {
        perror("shm_open failed");
        free(handle);
        return NULL;
    }

    // 크기 설정
    if (ftruncate(handle->fd, handle->total_size) == -1) {
        perror("ftruncate failed");
        close(handle->fd);
        free(handle);
        return NULL;
    }

    // 메모리 매핑
    handle->base_addr = mmap(NULL, handle->total_size, PROT_READ | PROT_WRITE, 
                             MAP_SHARED, handle->fd, 0);
    if (handle->base_addr == MAP_FAILED) {
        perror("mmap failed");
        close(handle->fd);
        free(handle);
        return NULL;
    }

    handle->shm = (memf_shm_t *)handle->base_addr;
    handle->data_region = (char *)handle->base_addr + sizeof(memf_shm_t);

    // 헤더 초기화
    handle->shm->header.magic = MEMF_INDEX_MAGIC;
    handle->shm->header.entry_count = 0;
    handle->shm->header.max_entries = MEMF_MAX_ENTRIES;
    handle->shm->header.data_offset = sizeof(memf_shm_t);
    handle->shm->header.data_size = data_size;
    handle->shm->header.data_used = 0;

    // 엔트리 초기화
    memset(handle->shm->entries, 0, sizeof(memf_index_entry_t) * MEMF_MAX_ENTRIES);

    return handle;
}

// 기존 공유 메모리 열기
memf_handle_t* memf_open(const char *name)
{
    if (!name) {
        fprintf(stderr, "Invalid name\n");
        return NULL;
    }

    memf_handle_t *handle = (memf_handle_t *)malloc(sizeof(memf_handle_t));
    if (!handle) {
        perror("malloc failed");
        return NULL;
    }

    // 공유 메모리 열기
    handle->fd = shm_open(name, O_RDWR, 0666);
    if (handle->fd == -1) {
        perror("shm_open failed");
        free(handle);
        return NULL;
    }

    // 크기 확인
    struct stat st;
    if (fstat(handle->fd, &st) == -1) {
        perror("fstat failed");
        close(handle->fd);
        free(handle);
        return NULL;
    }

    handle->total_size = st.st_size;

    // 메모리 매핑
    handle->base_addr = mmap(NULL, handle->total_size, PROT_READ | PROT_WRITE,
                             MAP_SHARED, handle->fd, 0);
    if (handle->base_addr == MAP_FAILED) {
        perror("mmap failed");
        close(handle->fd);
        free(handle);
        return NULL;
    }

    handle->shm = (memf_shm_t *)handle->base_addr;
    handle->data_region = (char *)handle->base_addr + sizeof(memf_shm_t);

    // 매직 넘버 확인
    if (handle->shm->header.magic != MEMF_INDEX_MAGIC) {
        fprintf(stderr, "Invalid shared memory format\n");
        munmap(handle->base_addr, handle->total_size);
        close(handle->fd);
        free(handle);
        return NULL;
    }

    return handle;
}

// 공유 메모리 닫기
int memf_close(memf_handle_t *handle)
{
    if (!handle) {
        return -1;
    }

    if (handle->base_addr) {
        munmap(handle->base_addr, handle->total_size);
    }

    if (handle->fd != -1) {
        close(handle->fd);
    }

    free(handle);
    return 0;
}

// 공유 메모리 삭제
int memf_destroy(const char *name)
{
    if (!name) {
        return -1;
    }

    return shm_unlink(name);
}

// 인덱스 엔트리 찾기
memf_index_entry_t* memf_find_entry(memf_handle_t *handle, const char *key)
{
    if (!handle || !key) {
        return NULL;
    }

    for (size_t i = 0; i < handle->shm->header.max_entries; i++) {
        if (handle->shm->entries[i].used && 
            strcmp(handle->shm->entries[i].key, key) == 0) {
            return &handle->shm->entries[i];
        }
    }

    return NULL;
}

// 데이터 쓰기
int memf_write(memf_handle_t *handle, const char *key, const void *data, size_t size)
{
    if (!handle || !key || !data || size == 0) {
        return -1;
    }

    // 기존 엔트리 확인
    memf_index_entry_t *entry = memf_find_entry(handle, key);
    
    if (entry) {
        // 기존 데이터 업데이트
        if (entry->size >= size) {
            // 같은 공간에 덮어쓰기
            memcpy((char *)handle->data_region + entry->offset, data, size);
            entry->size = size;
            return 0;
        } else {
            // 크기가 커진 경우 재할당 필요
            entry->used = 0;
            handle->shm->header.data_used -= entry->size;
        }
    }

    // 공간 확인
    if (handle->shm->header.data_used + size > handle->shm->header.data_size) {
        fprintf(stderr, "Not enough space in data region\n");
        return -1;
    }

    // 빈 엔트리 찾기
    memf_index_entry_t *new_entry = NULL;
    for (size_t i = 0; i < handle->shm->header.max_entries; i++) {
        if (!handle->shm->entries[i].used) {
            new_entry = &handle->shm->entries[i];
            break;
        }
    }

    if (!new_entry) {
        fprintf(stderr, "No free index entry\n");
        return -1;
    }

    // 데이터 쓰기
    size_t offset = handle->shm->header.data_used;
    memcpy((char *)handle->data_region + offset, data, size);

    // 인덱스 업데이트
    strncpy(new_entry->key, key, sizeof(new_entry->key) - 1);
    new_entry->key[sizeof(new_entry->key) - 1] = '\0';
    new_entry->offset = offset;
    new_entry->size = size;
    new_entry->used = 1;

    handle->shm->header.data_used += size;
    handle->shm->header.entry_count++;

    return 0;
}

// 데이터 읽기
int memf_read(memf_handle_t *handle, const char *key, void *data, size_t *size)
{
    if (!handle || !key || !data || !size) {
        return -1;
    }

    memf_index_entry_t *entry = memf_find_entry(handle, key);
    if (!entry) {
        fprintf(stderr, "Key not found: %s\n", key);
        return -1;
    }

    if (*size < entry->size) {
        fprintf(stderr, "Buffer too small\n");
        return -1;
    }

    memcpy(data, (char *)handle->data_region + entry->offset, entry->size);
    *size = entry->size;

    return 0;
}

// 데이터 삭제
int memf_delete(memf_handle_t *handle, const char *key)
{
    if (!handle || !key) {
        return -1;
    }

    memf_index_entry_t *entry = memf_find_entry(handle, key);
    if (!entry) {
        fprintf(stderr, "Key not found: %s\n", key);
        return -1;
    }

    // 엔트리 삭제 (단순 플래그 처리)
    entry->used = 0;
    handle->shm->header.entry_count--;
    
    // 주의: 실제 데이터 공간은 회수하지 않음 (단순화)
    // 실제 구현에서는 메모리 압축이나 프리 리스트 관리 필요

    return 0;
}

// 통계 정보 출력
void memf_print_stats(memf_handle_t *handle)
{
    if (!handle) {
        return;
    }

    printf("=== Shared Memory Statistics ===\n");
    printf("Magic: 0x%X\n", handle->shm->header.magic);
    printf("Total Size: %zu bytes\n", handle->total_size);
    printf("Index Size: %zu bytes\n", sizeof(memf_shm_t));
    printf("Data Region Size: %zu bytes\n", handle->shm->header.data_size);
    printf("Data Used: %zu bytes (%.2f%%)\n", 
           handle->shm->header.data_used,
           (double)handle->shm->header.data_used / handle->shm->header.data_size * 100);
    printf("Entry Count: %zu / %zu\n", 
           handle->shm->header.entry_count,
           handle->shm->header.max_entries);
    printf("\n=== Index Entries ===\n");
    
    int count = 0;
    for (size_t i = 0; i < handle->shm->header.max_entries && count < 10; i++) {
        if (handle->shm->entries[i].used) {
            printf("[%zu] Key: %s, Offset: %zu, Size: %zu\n",
                   i,
                   handle->shm->entries[i].key,
                   handle->shm->entries[i].offset,
                   handle->shm->entries[i].size);
            count++;
        }
    }
    
    if (handle->shm->header.entry_count > 10) {
        printf("... and %zu more entries\n", 
               handle->shm->header.entry_count - 10);
    }
}