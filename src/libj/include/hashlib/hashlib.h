#ifndef __HASHLIB__
#define __HASHLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define HASH_TABLE_SIZE 100

typedef struct hash_entry
{
    char *key;
    char *value;
    struct hash_entry *next;
} hash_entry_t;

typedef struct hash_table
{
    int size;
    hash_entry_t **table;
} hash_table_t;

extern hash_table_t *hash_table;

int print_hashlib();
int init_hash_table();
int insert_hash_table(const char *key, const char *value);
char *search_hash_table(const char *key);
int delete_hash_table(const char *key);

#endif