#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_SONGS 100
#define MUSICQUE_DIR ".music"
#define CAHCHE_FILE ".cache/musique_cache.dat"
#define HISTORY_FILE "musique_history.dat"

#endif
// COMMON_H