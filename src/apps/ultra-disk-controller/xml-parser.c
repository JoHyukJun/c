#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>


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
    char *docname;

    DIR *dd = NULL;
	struct dirent *entry = NULL;
	struct stat buff;

    char tmp_ext[128];
    char nfo_file[256];
    char *pos;

    memset(tmp_ext, 0x00, sizeof(tmp_ext));
    memset(nfo_file, 0x00, sizeof(nfo_file));

	if ((dd = opendir(nfo_dir_path)) == NULL) {
        printf("%s 를 열수 없습니다.\n", nfo_dir_path);

        return -1;
    }

    while ((entry = readdir(dd)) != NULL) {
        lstat(entry->d_name, &buff);

        if (entry->d_type == DT_DIR) {
            printf("[디렉토리이름] %s\n", entry->d_name);
        }
        else if (entry->d_type == DT_REG) {
            printf("[파일이름] %s\n", entry->d_name);

            pos = strchr(entry->d_name, '.');
            strcpy(tmp_ext, pos + 1);

            if (strcmp(tmp_ext, ext) == 0) {
                printf("[확장자] %s\n", tmp_ext);

                sprintf(nfo_file, "%s/%s", nfo_dir_path, entry->d_name);

                printf("파일위치: %s\n", nfo_file);

                parseDoc(nfo_file);
            }
        }
    }

	closedir(dd);

    return(1);
}