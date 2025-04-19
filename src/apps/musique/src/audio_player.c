#include <stdio.h>
#include <stdlib.h>

#include "audio_player.h"


// 터미널을 비버퍼 모드로 설정
void set_terminal_mode(int enable) {
    static struct termios oldt, newt;

    if (enable) {
        // 현재 터미널 설정 저장
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // 비버퍼 모드 설정 (ICANON 비활성화, ECHO 비활성화)
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // 파일 디스크립터를 논블로킹 모드로 설정
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    } else {
        // 이전 터미널 설정 복원
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

void play_audio(const Song* song)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Failed to ffplay fork");
        return;
    }

    if (pid == 0)
    {
        execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet", song->path, NULL);
        exit(0);
    }

    char command;
    int is_paused = 0;
    double current_time = 0.0;
    double duration = atof(song->duration);
    double last_update_time = -1.0;

    while (current_time <= duration) {
        // UI 업데이트
        if (current_time != last_update_time)
        {
            draw_player_ui(song->title, song->artist, song->album, duration, current_time); 
            last_update_time = current_time;
        }

        // `select`를 사용하여 입력 대기
        fd_set read_fds;
        struct timeval timeout;

        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);

        // 0.1초 타임아웃 설정
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        int ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

        if (ret > 0 && FD_ISSET(STDIN_FILENO, &read_fds)) {
            // 사용자 입력 처리
            if (read(STDIN_FILENO, &command, 1) > 0) {
                if (command == 'p') { // 재생/일시정지
                    if (is_paused) {
                        kill(pid, SIGCONT); // ffplay 프로세스 재개
                        printf("▶ Resumed\n");
                        is_paused = 0;
                    } else {
                        kill(pid, SIGSTOP); // ffplay 프로세스 일시정지
                        printf("⏸ Paused\n");
                        is_paused = 1;
                    }
                } else if (command == 'q') { // 종료
                    kill(pid, SIGKILL); // ffplay 프로세스 종료
                    printf("🛑 Stopped\n");
                    break;
                }
            }
        }

        // 재생 중일 때만 진행 시간 증가
        if (!is_paused) {
            current_time += 0.1; // 0.1초 단위로 진행
        }
    }

    // ffplay 프로세스가 종료될 때까지 대기
    kill(pid, SIGKILL); // 재생이 끝나면 ffplay 종료
    waitpid(pid, NULL, 0);
}
