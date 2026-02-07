#include <stdio.h>
#include "test.h"


void print_test()
{
    printf("test.c\n");
}

void test_memflib()
{
    memf_handle_t *handle;
    const char *shm_name = "/test_memf_shm";
    const char *key = "test_key";
    const char *data = "Hello, Shared Memory!";
    size_t data_size = strlen(data) + 1; // null 포함

    // 공유 메모리 생성
    handle = memf_create(shm_name, 1024);
    if (!handle) {
        fprintf(stderr, "Failed to create shared memory\n");
        return;
    }

    // 데이터 쓰기
    if (memf_write(handle, key, data, data_size) != 0) {
        fprintf(stderr, "Failed to write data\n");
        memf_close(handle);
        return;
    }

    memf_print_stats(handle);

    // 데이터 읽기
    char buffer[256];
    size_t read_size = sizeof(buffer);
    if (memf_read(handle, key, buffer, &read_size) != 0) {
        fprintf(stderr, "Failed to read data\n");
        memf_close(handle);
        return;
    }

    printf("Read data: %s\n", buffer);

    // 데이터 삭제
    if (memf_delete(handle, key) != 0) {
        fprintf(stderr, "Failed to delete data\n");
    }
    memf_print_stats(handle);

    // 공유 메모리 닫기
    memf_close(handle);

    // 공유 메모리 제거
    memf_destroy(shm_name);

    printf("memflib test completed\n");
}

void test_semlib()
{
    int t1;

    t1 = sem_create(TEST_SEM_KEY);

    printf("t1: %d\n", t1);

    sem_lock(t1);

    printf("lock\n");

    t1 = sem_create(TEST_SEM_KEY); 

    sem_unlock(t1);

    printf("unlock\n");
}

void test_filelib()
{
    /*
    * seqnof test
    */
    // int seqno = 0;

    // init_seqnof("./test.seq");

    // while (1)
    // {
    //     get_seqnof("./test.seq", seqno);

    //     print_current_time();
    //     printf("seqno: %d\n", seqno); 

    //     seqno++;

    //     set_seqnof("./test.seq", seqno);
    // }
    char filelist[9999];

    search_filelist_dir("../", filelist);

    printf("filelist: %s\n", filelist);
}

void test_jsonlib()
{
    int fd;
    char value[1024];

    fd = json_open("./test.json");

    json_get_element(fd, "TEST2_1", value);

    printf("value: %s\n", value);

    json_close(fd);
}

void test_sqlitelib()
{
    sqlite3 *db;

    sqlite_open("./test.db", &db);

    sqlite_exec(db, "CREATE TABLE TEST (ID INT, NAME TEXT);");

    sqlite_exec(db, "INSERT INTO TEST VALUES (1, 'TEST1');");
    sqlite_exec(db, "INSERT INTO TEST VALUES (2, 'TEST2');");
    sqlite_exec(db, "INSERT INTO TEST VALUES (3, 'TEST3');");

    sqlite_select(db, "SELECT * FROM TEST;", callback, NULL);

    sqlite_close(db);
}

void test_loglib()
{
    int fd;

    fd = log_open("./test.log");

    log_fp = get_logfile_ptr("./test.log");

    debug("test loglib");

    log_close(fd);
}

void test_hashlib()
{
    char *t_val;

    init_hash_table();

    insert_hash_table("TEST1", "VALUE1");
    insert_hash_table("TEST2", "VALUE2");
    insert_hash_table("TEST3", "VALUE3");

    t_val = search_hash_table("TEST1");

    insert_hash_table("TEST1", "VALUE4");

    t_val = search_hash_table("TEST1");
    
    printf("TEST1: %s\n", t_val);
}

int main()
{
    print_test();

    test_memflib();

    return (0);
}