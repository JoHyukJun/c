#include <stdio.h>
#include "test.h"


void print_test()
{
    printf("test.c\n");
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
    int seqno = 0;

    init_seqnof("./test.seq");

    while (1)
    {
        get_seqnof("./test.seq", seqno);

        print_current_time();
        printf("seqno: %d\n", seqno); 

        seqno++;

        set_seqnof("./test.seq", seqno);
    }
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

int main()
{
    print_test();

    test_sqlitelib();

    return (0);
}