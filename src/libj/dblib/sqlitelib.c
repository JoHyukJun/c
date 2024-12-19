#include "sqlitelib.h"


int print_sqlitelib()
{
    printf("SQLITELIB\n");

    return 0;
}

int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

int sqlite_open(dbname, db)
const char *dbname;
sqlite3 **db;
{
    if (sqlite3_open(dbname, db) != SQLITE_OK)
    {
        perror("sqlite3_open()");

        return (-1);
    }

    return (0);
}

int sqlite_close(db)
sqlite3 *db;
{
    if (sqlite3_close(db) != SQLITE_OK)
    {
        perror("sqlite3_close()");

        return (-1);
    }

    return (0);
}

int sqlite_exec(db, sql)
sqlite3 *db;
const char *sql;
{
    char *errmsg;

    if (sqlite3_exec(db, sql, 0, 0, &errmsg) != SQLITE_OK)
    {
        perror("sqlite3_exec()");

        return (-1);
    }

    return (0);
}

int sqlite_select(db, sql, callback, data)
sqlite3 *db;
const char *sql;
int (*callback)();
void *data;
{
    char *errmsg;

    if (sqlite3_exec(db, sql, callback, data, &errmsg) != SQLITE_OK)
    {
        perror("sqlite3_exec()");

        return (-1);
    }

    return (0);
}
