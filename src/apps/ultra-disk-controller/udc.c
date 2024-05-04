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
