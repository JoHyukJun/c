#include <stdio.h>
#include <string.h>

#include "file-handler.h"
#include "xml-parser.h"

int main(void)
{
    xml_parser(1);

    nfo_file nfo_files[128];

    memset(nfo_files, 0x00, sizeof(nfo_files));

    strcpy(nfo_files[0].path, "test_path");

    printf("%s", nfo_files[0].path);

    return 0;
}

