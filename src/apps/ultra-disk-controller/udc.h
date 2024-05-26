#ifndef __UDC__
#define __UDC__

#define NONE            0x000001
#define VALID_FILE      0x000002
#define PATH            0x000003
#define MAX_UDC         2048


struct _udc_file {
    int     type;
    char    path[1024];
    char    file_name[256];
    char    ext[8]; 
};
typedef struct _udc_file udc_file;
#define SZ_UDC_FILE sizeof(udc_file)


int init_udc_file_list(udc_file *udc_file_list, int udc_file_list_size);
void print_udc_file_list(const udc_file *udc_file_list, int udc_file_list_size);
int get_cur_index(const udc_file *udc_file_list, int udc_file_list_size);

#endif
