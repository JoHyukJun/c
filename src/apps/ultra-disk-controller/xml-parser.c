#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#include "xml-parser.h"


void parseActor(xmlDocPtr doc, xmlNodePtr cur) {
    xmlChar *key;
    cur = cur->xmlChildrenNode;
    while(cur != NULL) {
        if((!xmlStrcmp(cur->name, (const xmlChar *)"name"))) {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("name: %s\n", key);
            xmlFree(key);
        }
        cur = cur->next;
    }
    return;
}


static void parseDoc(char *docname) {
    xmlDocPtr doc;
    xmlNodePtr cur;
    doc = xmlParseFile(docname);

    if(doc == NULL) {
        fprintf(stderr, "Document not parsed successfully.\n");
        return;
    }
    cur = xmlDocGetRootElement(doc);

    if(cur == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return;
    }
    if(xmlStrcmp(cur->name, (const xmlChar *)"movie")) {
        fprintf(stderr, "document of the wrong type, root node != movie\n");
        xmlFreeDoc(doc);
        return;
    }
    cur = cur->xmlChildrenNode;

    while(cur != NULL) {
        if((!xmlStrcmp(cur->name, (const xmlChar *)"actor"))) {
            parseActor(doc, cur);
        }
        cur = cur->next;
    }
    xmlFreeDoc(doc);
    return;
}


int xml_parser(int number) {
    char        nfo_dir_path[128] = "./nfo_files";
    char        ext[16] = "nfo";
    char        docname[256];
    udc_file    udc_file_list[256];
    int         udc_file_idx;
    int         udc_file_list_length;

    udc_file_idx = 0;
    memset(docname, 0x00, sizeof(docname));

    udc_file_list_length = init_udc_file_list(udc_file_list, sizeof(udc_file_list));

    if (ultra_finder(nfo_dir_path, ext, udc_file_list) < 0) {
        printf("[ERR] ultra_finder\n");

        return (-1);
    }

    print_udc_file_list(udc_file_list, sizeof(udc_file_list));

    for (udc_file_idx = 0; udc_file_idx < udc_file_list_length; udc_file_idx++) {
        if (udc_file_list[udc_file_idx].type == NONE) {
            break;
        }

        sprintf(docname, "%s%s", udc_file_list[udc_file_idx].path, udc_file_list[udc_file_idx].file_name);

        parseDoc(docname);
    }

    return(1);
}