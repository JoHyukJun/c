#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#include "metadata.h"

int has_music_extension(const char* filename) {
    return strstr(filename, ".mp3") || strstr(filename, ".m4a") || strstr(filename, ".wav");
}

int get_album_name(const char* filepath, char* album_name_out, int max_len) {
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format_tags=album "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(album_name_out, max_len, pipe) != NULL) {
        album_name_out[strcspn(album_name_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int find_album_index(Album* albums, int count, const char* album_name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(albums[i].album_name, album_name) == 0) return i;
    }
    return -1;
}

int scan_music_files_recursive(const char* root_dir, Album* albums, int max_albums, int* album_count) {
    DIR* dp = opendir(root_dir);
    if (!dp) return 0;

    struct dirent* ep;

    while ((ep = readdir(dp)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0) {
            continue;
        }

        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", root_dir, ep->d_name);

        struct stat path_stat;
        if (stat(fullpath, &path_stat) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(path_stat.st_mode)) {
            // If it's a directory, recursively scan it
            scan_music_files_recursive(fullpath, albums, max_albums, album_count);
        } else if (S_ISREG(path_stat.st_mode) && has_music_extension(ep->d_name)) {
            // If it's a music file, process it
            char album_name[256] = "Unknown Album";
            get_album_name(fullpath, album_name, sizeof(album_name));

            int idx = find_album_index(albums, *album_count, album_name);
            if (idx == -1 && *album_count < max_albums) {
                idx = (*album_count)++;
                strncpy(albums[idx].album_name, album_name, sizeof(albums[idx].album_name));
                albums[idx].song_count = 0;
            }

            if (idx >= 0 && albums[idx].song_count < MAX_SONGS_PER_ALBUM) {
                strncpy(albums[idx].songs[albums[idx].song_count].title, ep->d_name, sizeof(albums[idx].songs[0].title));
                strncpy(albums[idx].songs[albums[idx].song_count].path, fullpath, sizeof(albums[idx].songs[0].path));
                albums[idx].song_count++;
            }
        }
    }

    closedir(dp);
    return *album_count;
}

int scan_music_files(const char* root_dir, Album* albums, int max_albums) {
    int album_count = 0;
    return scan_music_files_recursive(root_dir, albums, max_albums, &album_count);
}
