#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "file_scanner.h"


int has_music_extension(const char* name)
{
    return strstr(name, ".mp3") || strstr(name, ".wav") || strstr(name, ".m4a");
}

int scan_music_directory(const char* dir, MusicFile* list, int max_count) {
    DIR* dp = opendir(dir);

    if (!dp)
    {
        perror("Failed to open music directory\n");
        return (0);
    }

    struct dirent* ep;
    int count = 0;

    while ((ep = readdir(dp)) && count < max_count)
    {
        if (has_music_extension(ep->d_name))
        {
            snprintf(list[count].path, sizeof(list[count].path), "%s/%s", dir, ep->d_name);
            strncpy(list[count].title, ep->d_name, sizeof(list[count].title));
            count++;
        }
    }

    closedir(dp);
    return count;
}
