#ifndef METADATA_H
#define METADATA_H

#define MAX_SONGS_PER_ALBUM 100
#define MAX_ALBUMS 10240

typedef struct {
    char title[256]; // 파일 이름
    char artist[256]; // 아티스트 이름
    char album[256]; // 앨범 이름
    char genre[256]; // 장르
    char year[5]; // 연도
    char track_number[10]; // 트랙 번호
    char duration[10]; // 재생 시간
    char bitrate[10]; // 비트레이트
    char sample_rate[10]; // 샘플링 주파수
    char channels[10]; // 채널 수
    char file_size[20]; // 파일 크기
    char file_format[16]; // 파일 형식
    char file_extension[10]; // 파일 확장자
    char path[512];  // 전체 경로
} Song;
#define SZ_SONG sizeof(Song)

typedef struct {
    char album_name[256];
    Song songs[MAX_SONGS_PER_ALBUM];
    int song_count;
} Album;
#define SZ_ALBUM sizeof(Album)

int get_album_name(const char* filepath, char* album_name_out, int max_len);
int scan_music_files(const char* root_dir, Album* albums, int max_albums);

#endif
