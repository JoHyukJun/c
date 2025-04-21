#include "player_ui.h"


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

void file_size_to_human_readable(size, buffer, size_len)
const long long size;
char* buffer;
int size_len;
{
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;
    double size_in_unit = (double)size;

    while (size_in_unit >= 1024 && unit_index < 4)
    {
        size_in_unit /= 1024;
        unit_index++;
    }

    snprintf(buffer, size_len, "%.2f %s", size_in_unit, units[unit_index]);
}

// 곡 정보 박스 출력
void print_song_info(song)
const Song* song;
{
    char file_size_str[20];
    file_size_to_human_readable(atoll(song->file_size), file_size_str, sizeof(file_size_str));

    printf("📝 Title   : 「%s」\n", song->title);
    printf("🎤 Artist  : %s\n", song->artist);
    printf("💿 Album   : %s\n", song->album);
    printf("🎧 Bitrate : %s\n", song->bitrate);
    printf("🎶 Sample  : %s\n", song->sample_rate);
    printf("🔊 Channels: %s\n", song->channels);
    printf("📂 File    : %s\n", song->file_format);
    printf("📏 Size    : %s\n\n", file_size_str);
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
void draw_progress(double cur, double total)
{
    int width = 40;
    int filled = (int)((cur * width) / total);
    printf("\n⏯️ %02d:%05.2f / %02d:%05.2f   [",
           (int)(cur / 60), fmod(cur, 60.0),
           (int)(total / 60), fmod(total, 60.0));

    for (int i = 0; i < width; i++)
    {
        if (i < filled)
            printf("█");
        else
            printf("░");
    }

    printf("] %.2f%%\n", (cur * 100) / total);
}

// 전체 재생 UI
void draw_player_ui(song, duration_sec, current_time)
const Song* song;
double duration_sec;
double current_time;
{
    printf(CLEAR_SCREEN CURSOR_HOME);
    fflush(stdout);
    print_header();
    print_song_info(song);
    draw_waveform(current_time);
    draw_progress(current_time, duration_sec);
    fflush(stdout);
}