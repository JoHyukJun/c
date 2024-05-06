#ifndef __JFILEHANDLER__
#define __JFILEHANDLER__

#include "udc.h"

#define BUF_SIZE    4096


int jfinder(char *path, char *ext, udc_file *udc_file_list);
int ultra_finder(char *path, char *ext, udc_file *udc_file_list);
int jcopy(char *orgin_filename, char *destination_filename);

#endif
