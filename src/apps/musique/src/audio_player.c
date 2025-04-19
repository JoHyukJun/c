#include <stdio.h>
#include <stdlib.h>
#include "audio_player.h"

void play_audio(const char* filepath) {
    char command[512];
    snprintf(command, sizeof(command), "ffplay -nodisp -autoexit \"%s\"", filepath);
    system(command);
}
