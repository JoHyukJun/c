#ifndef __UDC__
#define __UDC__

struct _udc_file {
    char path[256];
};
typedef struct _udc_file udc_file;
#define SZ_UDC_FILE sizeof(udc_file)

#endif
