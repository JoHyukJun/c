#include "common.h"
#include "audio_player.h"
#include "file_scanner.h"
#include "user_profile.h"
#include "metadata.h"


int main()
{
    HistoryEntry history[MAX_HISTORY];
    int history_count = load_history(HISTORY_FILE, history, MAX_HISTORY);

    Album albums[MAX_ALBUMS];
    int count = scan_music_files(".music", albums, MAX_ALBUMS);

    if (count == 0)
    {
        printf("재생할 음악이 없습니다.\n");
        return 1;
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

    printf("🎵 음악 번호 선택: ");
    int song_choice;
    scanf("%d", &song_choice);

    if (song_choice < 1 || song_choice > albums[album_choice - 1].song_count)
    {
        printf("[%d:%d]잘못된 선택입니다.\n", song_choice, albums[album_choice].song_count);
        return 1;
    }

    play_audio(albums[album_choice - 1].songs[song_choice - 1].path);

    update_history(history, &history_count, albums[album_choice - 1].songs[song_choice - 1].path);
    save_history(HISTORY_FILE, history, history_count);

    printf("🎧 재생 기록 업데이트 완료.\n");

    printf("🎧 Top10 History\n");
    show_top_history(history, history_count, 10);

    return (0);
}
