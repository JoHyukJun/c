#include <stdio.h>
#include <string.h>
#include "user_profile.h"

int load_history(const char* filename, HistoryEntry* history, int max_entries) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return 0;

    int count = 0;
    while (fscanf(fp, "%[^|]|%d\n", history[count].path, &history[count].play_count) == 2) {
        count++;
        if (count >= max_entries) break;
    }

    fclose(fp);
    return count;
}

int save_history(const char* filename, HistoryEntry* history, int count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) return -1;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s|%d\n", history[i].path, history[i].play_count);
    }

    fclose(fp);
    return 0;
}

void update_history(HistoryEntry* history, int* count, const char* filepath) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(history[i].path, filepath) == 0) {
            history[i].play_count++;
            return;
        }
    }

    if (*count < MAX_HISTORY) {
        strncpy(history[*count].path, filepath, sizeof(history[*count].path));
        history[*count].play_count = 1;
        (*count)++;
    }
}
