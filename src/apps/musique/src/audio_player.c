#include <stdio.h>
#include <stdlib.h>

#include "audio_player.h"


void play_audio(const Song* song)
{
    if (fork() == 0)
    {
        execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet", song->path, NULL);
        exit(0);
    }

    draw_player_ui(song->title, song->artist, song->album, song->duration);
}
