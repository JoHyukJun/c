#include <stdio.h>
#include <string.h>

#include "udc.h"
#include "xml-parser.h"
#include "file-handler.h"

int main(void)
{
    char        source_path[FILENAME_MAX];
    char        video_ext[16];
    udc_file    nfo_file_list[MAX_UDC];
    udc_file    video_file_list[MAX_UDC];

    memset(source_path, 0x00, sizeof(source_path));
    memset(video_ext, 0x00, sizeof(video_ext));

    init_udc_file_list(nfo_file_list, sizeof(nfo_file_list));
    init_udc_file_list(video_file_list, sizeof(video_file_list));

    strcpy(source_path, "/Volumes/JO002TSE001/JO002TSE001/jo-drive/dev/test/st");
    strcpy(video_ext, "mp4");

    ultra_finder(source_path, video_ext, video_file_list);
    jfinder(source_path, video_ext, video_file_list);

    print_udc_file_list(video_file_list, sizeof(video_file_list));

    xml_parser(1);

    jcopy("/Volumes/JO002TSE001/JO002TSE001/jo-drive/dev/test/st/test.mp4", "/Volumes/JO002TSE001/JO002TSE001/jo-drive/dev/test/ds/test.mp4");

    return 0;
}
