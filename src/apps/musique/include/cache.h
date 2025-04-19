#ifndef CACHE_H
#define CACHE_H

#include "metadata.h"

#define MAX_CACHE_LINE 1024

void ensure_cache_directory();
int load_tag_cache(const char* path, Album* albums, int max_albums, const char* music_dir);
int save_tag_cache(const char* path, Album* albums, int album_count);

#endif
