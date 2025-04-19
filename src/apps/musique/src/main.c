#include "common.h"
#include "audio_player.h"
#include "file_scanner.h"
#include "user_profile.h"


int main()
{
    MusicFile songs[MAX_SONGS];
    int count = scan_music_directory(".music", songs, MAX_SONGS);

    if (count == 0)
    {
        printf("재생할 음악이 없습니다.\n");
        return 1;
    }

    printf("🎵 음악 리스트:\n");

    for (int i = 0; i < count; i++)
    {
        printf("[%d] %s\n", i + 1, songs[i].title);
    }

    printf("번호 선택: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > count)
    {
        printf("잘못된 선택입니다.\n");
        return 1;
    }

    HistoryEntry history[MAX_HISTORY];
    int history_count = load_history(HISTORY_FILE, history, MAX_HISTORY);

    play_audio(songs[choice - 1].path);

    update_history(history, &history_count, songs[choice - 1].path);
    save_history(HISTORY_FILE, history, history_count);


    return (0);
}
