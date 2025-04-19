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

        char filepath[512], album[256], artist[256], duration[10];
        long mtime;

        if (sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%ld", filepath, album, artist, duration, &mtime) != 5) continue;

        long current_mtime = get_mtime(filepath);

        if (current_mtime != mtime) continue;

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
            strncpy(albums[idx].songs[albums[idx].song_count].path, filepath, sizeof(albums[idx].songs[0].path));
            albums[idx].song_count++;
        }
    }

    fclose(fp);
    closedir(dp);
    return album_count;
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
            fprintf(fp, "%s|%s|%s|%s|%ld\n", song->path, albums[i].album_name, song->artist, song->duration, mtime);
        }
    }

    fclose(fp);
    return 1;
}
