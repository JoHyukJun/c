#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#include "metadata.h"

static int has_music_extension(const char* filename)
{
    return strstr(filename, ".mp3") || strstr(filename, ".m4a") || strstr(filename, ".wav");
}

int get_album_name(const char* filepath, char* album_name_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format_tags=album "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(album_name_out, max_len, pipe) != NULL)
    {
        album_name_out[strcspn(album_name_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_artist_name(const char* filepath, char* artist_name_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format_tags=artist "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(artist_name_out, max_len, pipe) != NULL)
    {
        artist_name_out[strcspn(artist_name_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_duration(const char* filepath, char* duration_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format=duration "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(duration_out, max_len, pipe) != NULL)
    {
        duration_out[strcspn(duration_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_bitrate(const char* filepath, char* bitrate_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format=bit_rate "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(bitrate_out, max_len, pipe) != NULL)
    {
        bitrate_out[strcspn(bitrate_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_sample_rate(const char* filepath, char* sample_rate_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries stream=sample_rate "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(sample_rate_out, max_len, pipe) != NULL)
    {
        sample_rate_out[strcspn(sample_rate_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_channels(const char* filepath, char* channels_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries stream=channels "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(channels_out, max_len, pipe) != NULL)
    {
        channels_out[strcspn(channels_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_file_size(const char* filepath, char* file_size_out, int max_len)
{
    struct stat st;
    if (stat(filepath, &st) == 0)
    {
        snprintf(file_size_out, max_len, "%lld", (long long)st.st_size);
        return 1;
    }
    return 0;
}

int get_file_format(const char* filepath, char* file_format_out, int max_len)
{
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "ffprobe -v quiet -show_entries format=format_name "
        "-of default=noprint_wrappers=1:nokey=1 \"%s\"", filepath);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return 0;

    if (fgets(file_format_out, max_len, pipe) != NULL)
    {
        file_format_out[strcspn(file_format_out, "\n")] = '\0'; // 개행 제거
        pclose(pipe);
        return 1;
    }

    pclose(pipe);
    return 0;
}

int get_file_extension(const char* filepath, char* file_extension_out, int max_len)
{
    const char* dot = strrchr(filepath, '.');
    if (!dot || dot == filepath) return 0;

    strncpy(file_extension_out, dot + 1, max_len);
    file_extension_out[max_len - 1] = '\0'; // Ensure null-termination
    return 1;
}

int find_album_index(Album* albums, int count, const char* album_name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(albums[i].album_name, album_name) == 0) return i;
    }
    return -1;
}

int scan_music_files_recursive(const char* root_dir, Album* albums, int max_albums, int* album_count)
{
    DIR* dp = opendir(root_dir);
    if (!dp) return 0;

    struct dirent* ep;

    while ((ep = readdir(dp)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
        {
            continue;
        }

        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", root_dir, ep->d_name);

        struct stat path_stat;

        if (stat(fullpath, &path_stat) == -1)
        {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(path_stat.st_mode))
        {
            // If it's a directory, recursively scan it
            scan_music_files_recursive(fullpath, albums, max_albums, album_count);
        }
        else if (S_ISREG(path_stat.st_mode) && has_music_extension(ep->d_name))
        {
            // If it's a music file, process it
            char album_name[256] = "Unknown Album";
            char artist_name[256] = "Unknown Artist";
            char duration[10] = "0";
            char bitrate[10] = "0";
            char sample_rate[10] = "0";
            char channels[10] = "0";
            char file_size[20] = "0";
            char file_format[16] = "Unknown";
            char file_extension[10] = "Unknown";

            get_album_name(fullpath, album_name, sizeof(album_name));
            get_artist_name(fullpath, artist_name, sizeof(artist_name));
            if (get_duration(fullpath, duration, sizeof(duration)) == 0)
            {
                snprintf(duration, sizeof(duration), "0");
            }
            get_bitrate(fullpath, bitrate, sizeof(bitrate));
            get_sample_rate(fullpath, sample_rate, sizeof(sample_rate));
            get_channels(fullpath, channels, sizeof(channels));
            get_file_size(fullpath, file_size, sizeof(file_size));
            get_file_format(fullpath, file_format, sizeof(file_format));
            get_file_extension(fullpath, file_extension, sizeof(file_extension));

            int idx = find_album_index(albums, *album_count, album_name);
            if (idx == -1 && *album_count < max_albums)
            {
                idx = (*album_count)++;
                strncpy(albums[idx].album_name, album_name, sizeof(albums[idx].album_name));
                albums[idx].song_count = 0;
            }

            if (idx >= 0 && albums[idx].song_count < MAX_SONGS_PER_ALBUM)
            {
                strncpy(albums[idx].songs[albums[idx].song_count].title, ep->d_name, sizeof(albums[idx].songs[0].title));
                strncpy(albums[idx].songs[albums[idx].song_count].artist, artist_name, sizeof(albums[idx].songs[0].artist));
                strncpy(albums[idx].songs[albums[idx].song_count].album, album_name, sizeof(albums[idx].songs[0].album));
                strncpy(albums[idx].songs[albums[idx].song_count].duration, duration, sizeof(albums[idx].songs[0].duration));
                strncpy(albums[idx].songs[albums[idx].song_count].bitrate, bitrate, sizeof(albums[idx].songs[0].bitrate));
                strncpy(albums[idx].songs[albums[idx].song_count].sample_rate, sample_rate, sizeof(albums[idx].songs[0].sample_rate));
                strncpy(albums[idx].songs[albums[idx].song_count].channels, channels, sizeof(albums[idx].songs[0].channels));
                strncpy(albums[idx].songs[albums[idx].song_count].file_size, file_size, sizeof(albums[idx].songs[0].file_size));
                strncpy(albums[idx].songs[albums[idx].song_count].file_format, file_format, sizeof(albums[idx].songs[0].file_format));
                strncpy(albums[idx].songs[albums[idx].song_count].file_extension, file_extension, sizeof(albums[idx].songs[0].file_extension));
                strncpy(albums[idx].songs[albums[idx].song_count].path, fullpath, sizeof(albums[idx].songs[0].path));
                albums[idx].song_count++;
            }
        }
    }

    closedir(dp);
    return *album_count;
}

int scan_music_files(const char* root_dir, Album* albums, int max_albums)
{
    int album_count = 0;
    return scan_music_files_recursive(root_dir, albums, max_albums, &album_count);
}
