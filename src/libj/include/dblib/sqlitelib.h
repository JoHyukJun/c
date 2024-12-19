#ifndef __SQLITELIB__
#define __SQLITELIB__

#include <stdio.h>
#include <sqlite3.h>


int print_sqlitelib();
int callback(void *data, int argc, char **argv, char **azColName);
int sqlite_open(const char *dbname, sqlite3 **db);
int sqlite_close(sqlite3 *db);
int sqlite_exec(sqlite3 *db, const char *sql);
int sqlite_select(sqlite3 *db, const char *sql, int (*callback)(), void *data);

#endif