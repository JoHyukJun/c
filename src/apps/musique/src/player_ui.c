#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CLEAR_SCREEN "\033[2J"
#define CURSOR_HOME "\033[H"
#define COLOR_RESET "\033[0m"
#define BOLD "\033[1m"
#define BG_GRAY "\033[48;5;236m"

// ANSI 그라데이션 컬러
const char* colors[] = {
    "\033[38;5;196m", "\033[38;5;202m", "\033[38;5;220m",
    "\033[38;5;46m",  "\033[38;5;51m",  "\033[38;5;93m",
    "\033[38;5;201m"
};

// 상단 헤더
void print_header() {
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║              🎧  ");
    printf("\033[1;36mMUSIQUE AUDIO PLAYER\033[0m");
    printf("  🎧            ║\n");
    printf("║              🎧  ");
    printf("\033[12;3mpowerd by UNLUCKY STRIKE\033[0m");
    printf("  🎧        ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n\n");
}

// 곡 정보 박스 출력
void print_song_info(const char* title, const char* artist, const char* album) {
    printf("📝 Title   : 「%s」\n", title);
    printf("🎤 Artist  : %s\n", artist);
    printf("💿 Album   : %s\n\n", album);
}

// 웨이브 시뮬레이션 출력
void draw_waveform(int tick) {
    const char* bars[] = {"░", "▒", "▓", "█"};
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 60; col++) {
            int level = rand() % 4;
            const char* color = colors[(tick + col + row) % 7];
            printf("%s%s", color, bars[level]);
        }
        printf(COLOR_RESET "\n");
    }
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

// 진행바
void draw_progress(int cur, int total) {
    int width = 40;
    int filled = (cur * width) / total;
    printf("\n⏯️ %02d:%02d / %02d:%02d   [",
           cur / 60, cur % 60,
           total / 60, total % 60);
    for (int i = 0; i < width; i++) {
        if (i < filled)
            printf("█");
        else
            printf("░");
    }
    printf("] %d%%\n", (cur * 100) / total);
}

// 전체 재생 UI
void draw_player_ui(const char* title, const char* artist, const char* album, int duration_sec) {
    srand(time(NULL));
    for (int sec = 0; sec <= duration_sec; sec++) {
        printf(CLEAR_SCREEN CURSOR_HOME);
        print_header();
        print_song_info(title, artist, album);
        draw_waveform(sec);
        draw_progress(sec, duration_sec);
        fflush(stdout);
        sleep(1);
    }
}
