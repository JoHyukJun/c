#include <stdio.h>
#include <string.h>

#include "ufc.h"
#include "xml-parser.h"
#include "file-handler.h"

int main(void)
{
    xml_parser(1);

    nfo_file nfo_file_list[128];

    memset(nfo_file_list, 0x00, sizeof(nfo_file_list));

    strcpy(nfo_file_list[0].path, "test_path");
    printf("%s\n", nfo_file_list[0].path);

    jcopy("./test/st/디지몬 어드벤쳐 - E01.모험의 섬.avi", "./test/ds/test.avi");

    return 0;
}

