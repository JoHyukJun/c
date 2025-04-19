#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "file_scanner.h"


int has_music_extension(name)
const char* name;
{
    return strstr(name, ".mp3") || strstr(name, ".wav") || strstr(name, ".m4a");
}

int scan_music_directory_recursive(dir, list, max_count, count)
const char* dir;
MusicFile* list;
int max_count;
int* count;
{
    DIR* dp = opendir(dir);

    if (!dp)
    {
        perror("Failed to open music directory\n");
        return 0;
    }

    struct dirent* ep;

    while ((ep = readdir(dp)) && *count < max_count)
    {
        // Skip "." and ".." entries
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
        {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, ep->d_name);

        struct stat path_stat;
        if (stat(full_path, &path_stat) == -1)
        {
            perror("Failed to get file status\n");
            continue;
        }

        if (S_ISDIR(path_stat.st_mode))
        {
            // If it's a directory, recursively scan it
            scan_music_directory_recursive(full_path, list, max_count, count);
        }
        else if (has_music_extension(ep->d_name))
        {
            // If it's a music file, add it to the list
            snprintf(list[*count].path, sizeof(list[*count].path), "%s", full_path);
            strncpy(list[*count].title, ep->d_name, sizeof(list[*count].title));
            (*count)++;
        }
    }

    closedir(dp);
    return *count;
}

int scan_music_directory(dir, list, max_count)
const char* dir;
MusicFile* list;
int max_count;
{
    int count = 0;
    return scan_music_directory_recursive(dir, list, max_count, &count);
}
