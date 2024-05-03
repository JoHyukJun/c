#include <stdio.h>
#include <string.h>

#include "udc.h"
#include "xml-parser.h"
#include "file-handler.h"

int main(void)
{
    xml_parser(1);

    udc_file udc_file_list[128];

    memset(udc_file_list, 0x00, sizeof(udc_file_list));

    strcpy(udc_file_list[0].path, "test_path");
    printf("%s\n", udc_file_list[0].path);

    jcopy("/Volumes/JO002TSE001/JO002TSE001/jo-drive/dev/test/st/test.mp4", "/Volumes/JO002TSE001/JO002TSE001/jo-drive/dev/test/ds/test.mp4");

    return 0;
}

