#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <utmp.h>


int main() {
    struct utmp *ut;

    while ((ut=getutent() != NULL)) {
        if (ut->ut_type != USER_PROCESS) {
            continue;
        }

        print("%s:%s:%d:%d\n", ut->ut_user, ut->ut_id, (int)ut->ut_tv.tv_sec, ut->ut_addr_v6);
    }
}