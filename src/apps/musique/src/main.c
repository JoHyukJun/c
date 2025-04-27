#include "common.h"
#include "audio_player.h"
#include "file_scanner.h"
#include "user_profile.h"
#include "metadata.h"
#include "cache.h"


void program_usage()
{
    printf("Usage: ./musique [options]\n");
    printf("Options:\n");
    printf("  -h, --help       Show this help message\n");
    printf("  -v, --version    Show version information\n");
    printf("  -c, --cache     Specify cache file path\n");
    printf("  -cc, --clear-cache  Clear the cache\n");
    printf("  -m, --music-dir  Specify music directory\n");
    printf("  -H, --history    Specify history file path\n");
}

void program_version()
{
    printf("Musique Player \n");
    printf("Powered by UNLUCKY STRIKE\n");
}

int main(argc, argv)
int argc;
char* argv[];
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            program_usage();
            return 0;
        }
        else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
        {
            program_version();
            return 0;
        }
        else if (strcmp(argv[1], "-cc") == 0 || strcmp(argv[1], "--clear-cache") == 0)
        {
            clear_cache(CAHCHE_FILE);
            printf("캐시 파일을 비웠습니다.\n");
            return 0;
        } 
    }

    printf("🎧 Musique Player\n");
    int count = 0;
    Album* albums = malloc(SZ_ALBUM * MAX_ALBUMS);

    if (!albums)
    {
    perror("Failed to allocate memory for albums");
    
    return (-1);
    }

    HistoryEntry history[MAX_HISTORY];
    int history_count = load_history(HISTORY_FILE, history, MAX_HISTORY);

    printf("🎧 재생 기록 로드 완료. %d개의 항목이 있습니다.\n", history_count);

    printf("🎧 음악 디렉토리: %s\n", MUSICQUE_DIR);
    count = update_cache(CAHCHE_FILE, albums, MAX_ALBUMS, MUSICQUE_DIR);

    if (count == 0)
    {
        printf("캐시 파일이 없습니다. ffprobe 분석 실행 중...\n");
        count = scan_music_files(MUSICQUE_DIR, albums, MAX_ALBUMS);
        save_tag_cache(CAHCHE_FILE, albums, count);

        if (count == 0)
        {
            printf("음악 파일을 찾을 수 없습니다.\n");
            return 1;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("📀 앨범: %s\n", albums[i].album_name);
        printf("   [앨범 번호] %d\n", i + 1);
        printf("   [앨범 경로] %s\n", albums[i].songs[0].path);
        printf("   [곡 수] %d\n", albums[i].song_count);
        printf("🎵 음악 리스트:\n");

        for (int j = 0; j < albums[i].song_count; j++)
        {
            printf("   [%d] %s\n", j + 1, albums[i].songs[j].title);
        }
        printf("\n");
    }

    printf("📀 앨범 번호 선택: ");
    int album_choice;
    scanf("%d", &album_choice);

    if (album_choice < 1 || album_choice > count)
    {
        printf("잘못된 선택입니다.\n");
        return 1;
    }

    printf("🎵 음악 번호 선택(랜덤 플레이: 0): ");
    int song_choice;
    scanf("%d", &song_choice);

    if (song_choice == 0)
    {
        printf("랜덤 플레이를 선택했습니다.\n");
        
        if (play_random_songs(&albums[album_choice - 1]) == 1)
        {
            printf("musique: SUCCESSFULLY PROGRAM EXITED.\n");
            
            return (1);
        }
        else
        {
            printf("랜덤 플레이 실패\n");
            
            return (-1);
        }
    }

    if (song_choice < 1 || song_choice > albums[album_choice - 1].song_count)
    {
        printf("[%d:%d]잘못된 선택입니다.\n", song_choice, albums[album_choice].song_count);
        
        return (-1);
    }

    play_audio(&albums[album_choice - 1].songs[song_choice - 1]);

    update_history(history, &history_count, albums[album_choice - 1].songs[song_choice - 1].path);
    save_history(HISTORY_FILE, history, history_count);

    printf("🎧 재생 기록 업데이트 완료.\n");

    printf("🎧 Top10 History\n");
    show_top_history(history, history_count, 10);

    return (0);
}
