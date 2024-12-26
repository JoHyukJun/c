#include "filelib.h"


int print_filelib()
{
    printf("FILELIB\n");

    return 0;
}

int fexist(filename) 
const char *filename;
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fclose(fp);

    return (1);
}

int ferase(filename)
const char *filename;
{
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fclose(fp);

    return (1);
}

int funlink(filename)
const char *filename;
{
    if (unlink(filename) == -1) {
        perror("unlink()");

        return (-1);
    }

    return (1);
}

int fcopy(src_filename, dst_filename)
const char *src_filename;
const char *dst_filename;
{
    FILE *sfp, *dfp;
    int ch;
    long src_size, copied_size = 0;

    if ((sfp = fopen(src_filename, "rb")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    if ((dfp = fopen(dst_filename, "wb")) == NULL) {
        perror("fopen()");
        fclose(sfp);

        return (-1);
    }

    // Get the size of the source file
    fseek(sfp, 0, SEEK_END);
    src_size = ftell(sfp);
    fseek(sfp, 0, SEEK_SET);

    while ((ch = fgetc(sfp)) != EOF) {
        fputc(ch, dfp);
        copied_size++;

        // Display progress bar
        int progress = (int)((copied_size / (double)src_size) * 100);
        printf("\rProgress: %d%%", progress);
        fflush(stdout);
    }

    printf("\n");

    fclose(dfp);
    fclose(sfp);

    return (1);
}

int init_seqnof(filename)
const char *filename;
{
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fwrite("0", 1, 1, fp);

    fclose(fp);

    return (1);
}

int set_seqnof(filename, seqno)
const char *filename;
int seqno;
{
    FILE *fp;

    if ((fp = fopen(filename, "r+")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fwrite(&seqno, sizeof(int), 1, fp);

    fclose(fp);

    return (1);
}

int get_seqnof(filename, seqno)
const char *filename;
int seqno;
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen()");

        return (-1);
    }
    
    fread(&seqno, sizeof(int), 1, fp);

    fclose(fp);

    return (1);
}

int get_filesize(filename, filesize)
const char *filename;
long *filesize;
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        perror("stat()");

        return (-1);
    }

    *filesize = st.st_size;

    return (1);
}

int get_filetime(filename, filetime)
const char *filename;
time_t *filetime;
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        perror("stat()");

        return (-1);
    }

    *filetime = st.st_mtime;

    return (1);
}

int get_filemode(filename, filemode)
const char *filename;
mode_t *filemode;
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        perror("stat()");

        return (-1);
    }

    *filemode = st.st_mode;

    return (1);
}

int get_fileowner(filename, fileowner)
const char *filename;
uid_t *fileowner;
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        perror("stat()");

        return (-1);
    }

    *fileowner = st.st_uid;

    return (1);
}

int get_filegroup(filename, filegroup)
const char *filename;
gid_t *filegroup;
{
    struct stat st;

    if (stat(filename, &st) == -1) {
        perror("stat()");

        return (-1);
    }

    *filegroup = st.st_gid;

    return (1);
}

int get_keyf(filename, keyf, key_size)
const char *filename;
char *keyf;
int key_size;
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fgets(keyf, key_size, fp);

    fclose(fp);

    return (1);
}

int set_keyf(filename, keyf, key_size)
const char *filename;
char *keyf;
int key_size;
{
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fputs(keyf, fp);

    fclose(fp);

    return (1);
}

int get_file_absolute_path(filename, abs_path)
const char *filename;
char *abs_path;
{
    char *ptr;

    if ((ptr = realpath(filename, abs_path)) == NULL) {
        perror("realpath()");

        return (-1);
    }

    return (1);
}

int get_file_relative_path(filename, rel_path)
const char *filename;
char *rel_path;
{
    char *ptr;

    if ((ptr = realpath(filename, rel_path)) == NULL) {
        perror("realpath()");

        return (-1);
    }

    return (1);
}

int get_file_extension(filename, ext)
const char *filename;
char *ext;
{
    char *ptr;

    if ((ptr = strrchr(filename, '.')) == NULL) {
        return (-1);
    }

    strcpy(ext, ptr);

    return (1);
}

int get_file_basename(filename, basename)
const char *filename;
char *basename;
{
    char *ptr;

    if ((ptr = strrchr(filename, '/')) == NULL) {
        return (-1);
    }

    strcpy(basename, ptr + 1);

    return (1);
}

int get_file_dirname(filename, dirname)
const char *filename;
char *dirname;
{
    char *ptr;

    if ((ptr = strrchr(filename, '/')) == NULL) {
        return (-1);
    }

    strncpy(dirname, filename, ptr - filename);

    return (1);
}

int search_filelist_dir(dirname, filelist)
const char *dirname;
char *filelist;
{
    DIR *dp;
    struct dirent *dent;
    char path[PATH_LEN_MAX];
    char abs_path[PATH_LEN_MAX];
    char abs_dirname[PATH_LEN_MAX];

    if (realpath(dirname, abs_dirname) == NULL)
    {
        perror("realpath()");
        
        return (-1);
    }

    if ((dp = opendir(dirname)) == NULL)
    {
        perror("opendir()");

        return (-1);
    }

    while ((dent = readdir(dp)) != NULL)
    {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", abs_dirname, dent->d_name);

        if (realpath(path, abs_path) == NULL)
        {
            perror("realpath()");
            closedir(dp);

            return (-1);
        }

        if (dent->d_type == DT_DIR)
        {
            search_filelist_dir(abs_path, filelist);
        }
        else
        {
            strcat(filelist, path);
            strcat(filelist, "\n");
        }
    }

    closedir(dp);

    return (1);
}