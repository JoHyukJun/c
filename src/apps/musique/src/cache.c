#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "cache.h"
#include "metadata.h"


void ensure_cache_directory()
{
    struct stat st = {0};

    // 캐시 디렉토리가 없으면 생성
    if (stat(".cache", &st) == -1)
    {
        mkdir(".cache", 0700);
    }
}

int has_music_extension(const char* filename);

// mtime 가져오기
long get_mtime(const char* path)
{
    struct stat attr;

    if (stat(path, &attr) == 0) return attr.st_mtime;

    return 0;
}

long get_directory_mtime(path)
const char* path;
{
    struct stat attr;

    if (stat(path, &attr) == 0) return attr.st_mtime;

    return (0);
}

int save_directory_mtime(path, dir_mtime)
const char* path;
long dir_mtime;
{
    FILE* fp = fopen(path, "a");

    if (!fp) return 0;

    fprintf(fp, "DIR_MTIME|%ld\n", dir_mtime);

    fclose(fp);

    return (1);
}

int load_directory_mtime(path)
const char* path;
{
    FILE* fp = fopen(path, "r");
    if (!fp) return 0;

    char line[MAX_CACHE_LINE];
    long dir_mtime = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (strncmp(line, "DIR_MTIME|", 10) == 0)
        {
            sscanf(line, "DIR_MTIME|%ld", &dir_mtime);
            break;
        }
    }

    fclose(fp);

    return dir_mtime;
}

// 앨범 인덱스 찾기
static int find_album_index(Album* albums, int count, const char* album_name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(albums[i].album_name, album_name) == 0) return i;
    }
    return -1;
}

int clear_cache(const char* path)
{
    FILE* fp = fopen(path, "w");

    if (!fp) return 0;
    // 캐시 파일을 비우기

    fclose(fp);
    return 1;
}

// 캐시 로딩
int load_tag_cache(const char* path, Album* albums, int max_albums, const char* music_dir)
{
    FILE* fp = fopen(path, "r");
    if (!fp) return 0;

    DIR* dp = opendir(music_dir);

    if (!dp)
    {
        fclose(fp);
        return 0;
    }

    int album_count = 0;

    char line[MAX_CACHE_LINE];

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0';

        char filepath[512], album[256], artist[256], duration[10], bitrate[10], sample_rate[10], channels[10], file_size[20], file_format[16];
        long mtime;

        if (sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%ld", filepath, album, artist, duration, bitrate, sample_rate, channels, file_size, file_format, &mtime) != 10) continue;

        long current_mtime = get_mtime(filepath);

        if (current_mtime != mtime)
        {
            continue;
        }
        else
        {
            printf("cached: %s\n", filepath);
        }

        const char* filename = strrchr(filepath, '/');
        if (!filename) filename = filepath;
        else filename++;

        int idx = find_album_index(albums, album_count, album);

        if (idx == -1 && album_count < max_albums)
        {
            idx = album_count++;
            strncpy(albums[idx].album_name, album, sizeof(albums[idx].album_name));
            albums[idx].song_count = 0;
        }

        if (idx >= 0)
        {
            strncpy(albums[idx].songs[albums[idx].song_count].title, filename, sizeof(albums[idx].songs[0].title));
            strncpy(albums[idx].songs[albums[idx].song_count].artist, artist, sizeof(albums[idx].songs[0].artist));
            strncpy(albums[idx].songs[albums[idx].song_count].album, album, sizeof(albums[idx].songs[0].album));
            strncpy(albums[idx].songs[albums[idx].song_count].duration, duration, sizeof(albums[idx].songs[0].duration));
            strncpy(albums[idx].songs[albums[idx].song_count].bitrate, bitrate, sizeof(albums[idx].songs[0].bitrate));
            strncpy(albums[idx].songs[albums[idx].song_count].sample_rate, sample_rate, sizeof(albums[idx].songs[0].sample_rate));
            strncpy(albums[idx].songs[albums[idx].song_count].channels, channels, sizeof(albums[idx].songs[0].channels));
            strncpy(albums[idx].songs[albums[idx].song_count].file_size, file_size, sizeof(albums[idx].songs[0].file_size));
            strncpy(albums[idx].songs[albums[idx].song_count].file_format, file_format, sizeof(albums[idx].songs[0].file_format));
            strncpy(albums[idx].songs[albums[idx].song_count].path, filepath, sizeof(albums[idx].songs[0].path));
            albums[idx].song_count++;
        }
    }

    fclose(fp);
    closedir(dp);

    return album_count;
}

int update_cache(path, albums, max_albums, music_dir)
const char* path;
Album* albums;
int max_albums;
const char* music_dir;
{
    long current_dir_mtime = get_directory_mtime(music_dir);
    long cached_dir_mtime = load_directory_mtime(path);

    if (current_dir_mtime != cached_dir_mtime)
    {
        printf("디렉토리 변화 감지되었습니다. 캐시를 새로 생성합니다...\n");

        clear_cache(path);

        int album_count = scan_music_files(music_dir, albums, max_albums);
        
        save_tag_cache(path, albums, album_count);
        save_directory_mtime(path, current_dir_mtime);

        return album_count;
    }

    return load_tag_cache(path, albums, max_albums, music_dir);
}


// 캐시 저장
int save_tag_cache(const char* path, Album* albums, int album_count)
{
    FILE* fp = fopen(path, "w");
    if (!fp) return 0;

    for (int i = 0; i < album_count; i++)
    {
        for (int j = 0; j < albums[i].song_count; j++)
        {
            const Song* song = &albums[i].songs[j];
            long mtime = get_mtime(song->path);
            fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%ld\n", song->path, albums[i].album_name, song->artist, song->duration, song->bitrate, song->sample_rate, song->channels, song->file_size, song->file_format, mtime);
        }
    }

    fclose(fp);
    return 1;
}
