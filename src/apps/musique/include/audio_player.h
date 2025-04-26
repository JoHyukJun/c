#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "player_ui.h"
#include "metadata.h"


void play_audio(const Song* song);
int play_random_songs(const Album* album);

#endif
