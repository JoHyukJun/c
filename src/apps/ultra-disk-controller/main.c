#include <stdio.h>
#include <string.h>

#include "ufc.h"
#include "xml-parser.h"

int main(void)
{
    xml_parser(1);

    nfo_file nfo_file_list[128];

    memset(nfo_file_list, 0x00, sizeof(nfo_file_list));

    strcpy(nfo_file_list[0].path, "test_path");
    printf("%s", nfo_file_list[0].path);

    return 0;
}

