#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
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
void print_header()
{
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                ║\n");
    printf("║                                🎵  \033[1;36mMUSIQUE AUDIO PLAYER\033[0m  🎵                                    ║\n");
    printf("║                                                                                                ║\n");
    printf("║                        \033[1;33mPowered by UNLUCKY STRIKE - Enjoy Your Music!\033[0m                           ║\n");
    printf("║                                                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
}

// 곡 정보 박스 출력
void print_song_info(const char* title, const char* artist, const char* album) {
    printf("📝 Title   : 「%s」\n", title);
    printf("🎤 Artist  : %s\n", artist);
    printf("💿 Album   : %s\n\n", album);
}

// 웨이브 시뮬레이션 출력
void draw_waveform(double tick) {
    const char* bars[] = {"░", "▒", "▓", "█"};
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 98; col++) {
            int level = rand() % 4;
            const char* color = colors[((int)(tick * 10) + col + row) % 7];
            printf("%s%s", color, bars[level]);
        }
        printf(COLOR_RESET "\n");
    }
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

// 진행바
void draw_progress(double cur, double total) {
    int width = 40;
    int filled = (int)((cur * width) / total);
    printf("\n⏯️ %02d:%05.2f / %02d:%05.2f   [",
           (int)(cur / 60), fmod(cur, 60.0),
           (int)(total / 60), fmod(total, 60.0));
    for (int i = 0; i < width; i++) {
        if (i < filled)
            printf("█");
        else
            printf("░");
    }
    printf("] %.2f%%\n", (cur * 100) / total);
}

// 전체 재생 UI
void draw_player_ui(title, artist, album, duration_sec)
const char* title;
const char* artist;
const char* album;
const char* duration_sec;

{
    double duration_sec_f = atof(duration_sec);
    if (duration_sec <= 0) {
        printf("Invalid duration: %s\n", duration_sec);
        return;
    }

    srand(time(NULL));

    for (double sec = 0; sec <= duration_sec_f; sec += 0.1)
    {
        printf(CLEAR_SCREEN CURSOR_HOME);
        print_header();
        print_song_info(title, artist, album);
        draw_waveform(sec);
        draw_progress(sec, duration_sec_f);
        fflush(stdout);
        usleep(100000); // 0.1초 대기
    }
}