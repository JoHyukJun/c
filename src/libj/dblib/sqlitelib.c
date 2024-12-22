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

int sqlite_prepare(db, sql, stmt)
sqlite3 *db;
const char *sql;
sqlite3_stmt **stmt;
{
    if (sqlite3_prepare_v2(db, sql, -1, stmt, 0) != SQLITE_OK)
    {
        perror("sqlite3_prepare_v2()");

        return (-1);
    }

    return (0);
}

int sqlite_step(stmt)
sqlite3_stmt *stmt;
{
    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        perror("sqlite3_step()");

        return (-1);
    }

    return (0);
}

int sqlite_column_int(stmt, col)
sqlite3_stmt *stmt;
int col;
{
    return sqlite3_column_int(stmt, col);
}

const unsigned char *sqlite_column_text(stmt, col)
sqlite3_stmt *stmt;
int col;
{
    return sqlite3_column_text(stmt, col);
}

int sqlite_finalize(stmt)
sqlite3_stmt *stmt;
{
    if (sqlite3_finalize(stmt) != SQLITE_OK)
    {
        perror("sqlite3_finalize()");

        return (-1);
    }

    return (0);
}

int sqlite_reset(stmt)
sqlite3_stmt *stmt;
{
    if (sqlite3_reset(stmt) != SQLITE_OK)
    {
        perror("sqlite3_reset()");

        return (-1);
    }

    return (0);
}

int sqlite_bind_int(stmt, idx, val)
sqlite3_stmt *stmt;
int idx;
int val;
{
    if (sqlite3_bind_int(stmt, idx, val) != SQLITE_OK)
    {
        perror("sqlite3_bind_int()");

        return (-1);
    }

    return (0);
}

int sqlite_bind_text(stmt, idx, val)
sqlite3_stmt *stmt;
int idx;
const char *val;
{
    if (sqlite3_bind_text(stmt, idx, val, -1, SQLITE_STATIC) != SQLITE_OK)
    {
        perror("sqlite3_bind_text()");

        return (-1);
    }

    return (0);
}

int sqlite_bind_blob(stmt, idx, val, len)
sqlite3_stmt *stmt;
int idx;
const void *val;
int len;
{
    if (sqlite3_bind_blob(stmt, idx, val, len, SQLITE_STATIC) != SQLITE_OK)
    {
        perror("sqlite3_bind_blob()");

        return (-1);
    }

    return (0);
}

int sqlite_column_count(stmt)
sqlite3_stmt *stmt;
{
    return sqlite3_column_count(stmt);
}

int sqlite_column_type(stmt, col)
sqlite3_stmt *stmt;
int col;
{
    return sqlite3_column_type(stmt, col);
}

int sqlite_column_int(stmt, col)
sqlite3_stmt *stmt;
int col;
{
    return sqlite3_column_int(stmt, col);
}

