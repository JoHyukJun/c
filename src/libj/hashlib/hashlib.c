#include "hashlib.h"


hash_table_t *hash_table = NULL;

int print_hashlib()
{
    printf("HASHLIB\n");

    return 0;
}

int init_hash_table()
{
    int i;

    hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (hash_table == NULL)
    {
        perror("malloc()");

        return (-1);
    }

    hash_table->size = HASH_TABLE_SIZE;
    hash_table->table = (hash_entry_t **)malloc(sizeof(hash_entry_t *) * HASH_TABLE_SIZE);

    if (hash_table->table == NULL)
    {
        perror("malloc()");

        return (-1);
    }

    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hash_table->table[i] = NULL;
    }

    return (0);
}

int hash(key)
const char *key;
{
    int hash = 0;
    int i;

    for (i = 0; i < strlen(key); i++)
    {
        hash = (hash << 5) + key[i];
    }

    return hash;
}

int insert_hash_table(key, value)
const char *key;
const char *value;
{
    int index;
    hash_entry_t *entry;

    index = hash(key) % HASH_TABLE_SIZE;

    entry = (hash_entry_t *)malloc(sizeof(hash_entry_t));

    if (entry == NULL)
    {
        perror("malloc()");

        return (-1);
    }

    entry->key = strdup(key);

    if (entry->key == NULL)
    {
        perror("strdup()");

        return (-1);
    }

    entry->value = strdup(value);

    if (entry->value == NULL)
    {
        perror("strdup()");

        return (-1);
    }

    entry->next = hash_table->table[index];
    hash_table->table[index] = entry;

    return (0);
}

int delete_hash_table(key)
const char *key;
{
    int index;
    hash_entry_t *entry;
    hash_entry_t *prev;

    index = hash(key) % HASH_TABLE_SIZE;

    entry = hash_table->table[index];
    prev = NULL;

    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            if (prev == NULL)
            {
                hash_table->table[index] = entry->next;
            }
            else
            {
                prev->next = entry->next;
            }

            free(entry->key);
            free(entry->value);
            free(entry);

            return (0);
        }

        prev = entry;
        entry = entry->next;
    }

    return (-1);
}

char *search_hash_table(key)
const char *key;
{
    int index;
    hash_entry_t *entry;

    index = hash(key) % HASH_TABLE_SIZE;

    entry = hash_table->table[index];

    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return (entry->value);
        }

        entry = entry->next;
    }

    return (NULL);
}

int exsits_hash_table(key)
const char *key;
{
    int index;
    hash_entry_t *entry;

    index = hash(key) % HASH_TABLE_SIZE;

    entry = hash_table->table[index];

    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return (1);
        }

        entry = entry->next;
    }

    return (0);
}
