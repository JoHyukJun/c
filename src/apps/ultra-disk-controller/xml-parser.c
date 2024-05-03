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
    char nfo_dir_path[128] = "./nfo_files";
    char ext[128] = "nfo";


    udc_file udc_file_list[256];

    memset(udc_file_list, 0x00, sizeof(udc_file_list));

    ultra_finder(nfo_dir_path, ext, &udc_file_list);

    printf("xml_parser udc_file_test: %s", udc_file_list[0].path);

    return(1);
}