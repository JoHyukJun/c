#include <stdio.h>
#include <string.h>

#include "udc.h"


int init_udc_file_list(udc_file *udc_file_list, int udc_file_list_size)
{
    int         udc_file_idx;
    int         udc_file_list_length;

    udc_file_list_length = 0;
    memset(udc_file_list, 0x00, udc_file_list_size);

    udc_file_list_length = udc_file_list_size / SZ_UDC_FILE;

    printf("udc_file_list_length: %d\n", udc_file_list_length);

    for (udc_file_idx = 0; udc_file_idx < udc_file_list_length; udc_file_idx++) {
        udc_file_list[udc_file_idx].type = NONE;
    }

    return (udc_file_list_length);
}

void print_udc_file_list(const udc_file *udc_file_list, int udc_file_list_size)
{
    int         udc_file_idx;
    int         udc_file_list_length;

    udc_file_list_length = udc_file_list_size / SZ_UDC_FILE;

    for (udc_file_idx = 0; udc_file_idx < udc_file_list_length; udc_file_idx++) {
        if (udc_file_list[udc_file_idx].type == NONE) {
            break;
        }

        printf("===================================\n");
        printf("udc_file [index:%d]\n", udc_file_idx);
        printf("udc_file [type:%d]\n", udc_file_list[udc_file_idx].type);
        printf("udc_file [path:%s]\n", udc_file_list[udc_file_idx].path);
        printf("udc_file [file_name:%s]\n", udc_file_list[udc_file_idx].file_name);
        printf("udc_file [ext:%s]\n", udc_file_list[udc_file_idx].ext);
        printf("===================================\n");
    }
}


int get_cur_index(const udc_file *udc_file_list, int udc_file_list_size)
{
    int         retval = 0;
    int         udc_file_idx, udc_file_list_length;

    udc_file_list_length = 0;

    udc_file_list_length = udc_file_list_size / SZ_UDC_FILE;

    for (udc_file_idx = 0; udc_file_idx < udc_file_list_length; udc_file_idx++) {
        if (udc_file_list[udc_file_idx].type == NONE) {
            break;
        }

        retval += 1;
    }

    printf("get_cur_idx: %d\n", retval);

    return retval;
}