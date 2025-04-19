#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

typedef struct {
    char path[256];
    char title[100];
} MusicFile;

int scan_music_directory(const char* dir, MusicFile* list, int max_count);

#endif
// FILE_SCANNER_H