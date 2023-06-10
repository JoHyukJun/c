#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    stat("jo.txt", &statbuf);

    printf("<파일의 inode 번호> Inode = %d\n", (int)statbuf.st_ino);
    printf("<파일의 종류와 접근 권한> Mode = %o\n", (unsigned int)statbuf.st_mode);
    printf("<하드 링크의 개수> Nlink = %o\n", (unsigned int)statbuf.st_nlink);
    printf("<파일 소유자의 UID> UID = %d\n", (int)statbuf.st_uid);
    printf("<파일 소유 그룹의 GID> GID = %d\n", (int)statbuf.st_gid);
    printf("SIZE = %d\n", (int)statbuf.st_size);
    printf("<파일 입출력할 때 사용하는 버퍼 크기> Blksize = %d\n", (int)statbuf.st_blksize);
    printf("<파일에 할당된 파일 시스템의 블록 수> Blocks = %d\n", (int)statbuf.st_blocks);

    printf("** timespec style **\n");
    printf("<마지막으로 파일을 읽거나 실행한 시각> Atime = %d\n", (int)statbuf.st_atime.tv_sec);
    printf("<마지막으로 파일의 내용을 변경한 시각> Mtime = %d\n", (int)statbuf.st_mtime.tv_sec);
    printf("<마지막으로 inode의 내용을 변경한 시각> Ctime = %d\n", (int)statbuf.st_ctime.tv_sec);

    printf("** old style **\n");
    printf("Atime = %d\n", (int)statbuf.st_atime);
    printf("Mtime = %d\n", (int)statbuf.st_mtime);
    printf("Ctime = %d\n", (int)statbuf.st_ctime);
}