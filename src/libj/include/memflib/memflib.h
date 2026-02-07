#ifndef __MEMFLIB__
#define __MEMFLIB__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define MEMF_INDEX_MAGIC 0x4D454D46  // "MEMF"
#define MEMF_MAX_ENTRIES 100000000  // 최대 인덱스 엔트리 수 

// 인덱스 엔트리 구조체
typedef struct memf_index_entry
{
    char key[64];           // 키 값
    size_t offset;          // 데이터 영역에서의 오프셋
    size_t size;            // 데이터 크기
    int used;               // 사용 여부 (0: 미사용, 1: 사용중)
} memf_index_entry_t;

// 인덱스 헤더 구조체
typedef struct memf_index_header
{
    unsigned int magic;     // 매직 넘버
    size_t entry_count;     // 현재 엔트리 개수
    size_t max_entries;     // 최대 엔트리 개수
    size_t data_offset;     // 데이터 영역 시작 오프셋
    size_t data_size;       // 데이터 영역 전체 크기
    size_t data_used;       // 데이터 영역 사용량
} memf_index_header_t;

// 공유 메모리 전체 구조체
typedef struct memf_shm
{
    memf_index_header_t header;
    memf_index_entry_t entries[MEMF_MAX_ENTRIES];
    // 이후 데이터 영역이 이어짐
} memf_shm_t;

// 공유 메모리 핸들
typedef struct memf_handle
{
    int fd;                 // 파일 디스크립터
    void *base_addr;        // 공유 메모리 베이스 주소
    size_t total_size;      // 전체 크기
    memf_shm_t *shm;        // 공유 메모리 포인터
    void *data_region;      // 데이터 영역 포인터
} memf_handle_t;

// 공유 메모리 생성 및 초기화
memf_handle_t* memf_create(const char *name, size_t data_size);

// 기존 공유 메모리 열기
memf_handle_t* memf_open(const char *name);

// 공유 메모리 닫기
int memf_close(memf_handle_t *handle);

// 공유 메모리 삭제
int memf_destroy(const char *name);

// 데이터 쓰기
int memf_write(memf_handle_t *handle, const char *key, const void *data, size_t size);

// 데이터 읽기
int memf_read(memf_handle_t *handle, const char *key, void *data, size_t *size);

// 데이터 삭제
int memf_delete(memf_handle_t *handle, const char *key);

// 인덱스 엔트리 찾기
memf_index_entry_t* memf_find_entry(memf_handle_t *handle, const char *key);

// 통계 정보 출력
void memf_print_stats(memf_handle_t *handle);

// 기존 함수
int print_memflib();
int memf_init();

#endif
