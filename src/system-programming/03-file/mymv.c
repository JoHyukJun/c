#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
 
int file_del(char *file_name)
{
	int unlink_retval = unlink(file_name);
	if (unlink_retval != 0)
	{
		return 1;
	}
	return 0;
}
 
int main(int argc, char *argv[])
{
	char buffer[1024];
	FILE* fdin;
	FILE* fdout;
	int nread;
	int file_del_retval;

    char* target_file_name;
    char* next_dir_name;

    char* cur_dir;
    char* org_dir;
    char* next_dir;

    target_file_name = argv[1];
    next_dir_name = argv[2];
 
	fdin = fopen(target_file_name, "rb");
	if (fdin == NULL)
	{
		printf("fopen() failed, %s not found \n", argv[1]);
		exit(1);
	}

    org_dir = getcwd(NULL, BUFSIZ);

    printf("CUR DIR: %s\n", org_dir);

    chdir(next_dir_name);

    cur_dir = getcwd(NULL, BUFSIZ);

    printf("CUR DIR: %s\n", cur_dir);
 
	fdout = fopen(target_file_name, "wb");
	if (fdout == NULL)
	{
		printf("fopen() filed, %s not fount \n", argv[1]);
		exit(1);
	}
 
	while ((nread = fread(buffer, 1, 1, fdin)) > 0)
	{
		if (fwrite(buffer,nread,1,fdout) < nread)
		{
			fclose(fdin);
			fclose(fdout);
		}
	}
    
	fclose(fdin);
	fclose(fdout);

    chdir(org_dir);

    cur_dir = getcwd(NULL, BUFSIZ);
 
	file_del_retval = file_del(target_file_name);
	if (0 != file_del_retval) {
		printf("file (%s) delete fail. \n", target_file_name);
	}
 
	return 0;
}