#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#define MAX_HISTORY 100

typedef struct {
    char path[256];
    int play_count;
} HistoryEntry;

int load_history(const char* filename, HistoryEntry* history, int max_entries);
int save_history(const char* filename, HistoryEntry* history, int count);
void update_history(HistoryEntry* history, int* count, const char* filepath);
void show_top_history(HistoryEntry* history, int count, int top_n);

#endif
// USER_PROFILE_H