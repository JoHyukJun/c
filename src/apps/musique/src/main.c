#include <stdio.h>
#include "audio_player.h"
#include "file_scanner.h"

#define MAX_SONGS 100

int main() {
    MusicFile songs[MAX_SONGS];
    int count = scan_music_directory(".music", songs, MAX_SONGS);

    if (count == 0) {
        printf("재생할 음악이 없습니다.\n");
        return 1;
    }

    printf("🎵 음악 리스트:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i + 1, songs[i].title);
    }

    printf("번호 선택: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("잘못된 선택입니다.\n");
        return 1;
    }

    play_audio(songs[choice - 1].path);
    return 0;
}
