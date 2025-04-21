#ifndef PLAYER_UI_H
#define PLAYER_UI_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "metadata.h"

#define CLEAR_SCREEN "\033[2J"
#define CURSOR_HOME "\033[H"
#define COLOR_RESET "\033[0m"
#define BOLD "\033[1m"
#define BG_GRAY "\033[48;5;236m"

void draw_player_ui(const Song* song, double duration_sec, double current_time);

#endif
// PLAYER_UI_H