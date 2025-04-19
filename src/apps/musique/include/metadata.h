#ifndef METADATA_H
#define METADATA_H

#define MAX_SONGS_PER_ALBUM 100
#define MAX_ALBUMS 100

typedef struct {
    char title[256]; // 파일 이름
    char path[512];  // 전체 경로
} Song;

typedef struct {
    char album_name[256];
    Song songs[MAX_SONGS_PER_ALBUM];
    int song_count;
} Album;

int get_album_name(const char* filepath, char* album_name_out, int max_len);
int scan_music_files(const char* root_dir, Album* albums, int max_albums);

#endif
