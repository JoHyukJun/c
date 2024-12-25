#include "shmlib.h"


int print_samlib()
{
    printf("SAMLIB\n");

    return 0;
}

int shm_open(key)
key_t key;
{
    int shmid;

    shmid = shmget(key, SHM_SET_LEN, IPC_CREAT | 0644);

    if (shmid == -1)
    {
        perror("shmget()");

        return (-1);
    }

    return (shmid);
}

int shm_create(key)
key_t key;
{
    int shmid;

    shmid = shmget(key, SHM_SET_LEN, IPC_CREAT | IPC_EXCL | 0644);

    if (shmid == -1 && errno == EEXIST)
    {
        shmid = shmget(key, SHM_SET_LEN, 0);

        if (shmid == -1)
        {
            perror("shmget()");

            return (-1);
        }
    }

    return (shmid);
}

int shm_delete(shmid)
int shmid;
{
    if (shmctl(shmid, 0, IPC_RMID) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_write(shmid, buf, buf_size)
int shmid;
char *buf;
int buf_size;
{
    char *shmaddr;

    shmaddr = shmat(shmid, (char *)0, 0);

    if (shmaddr == (char *)-1)
    {
        perror("shmat()");

        return (-1);
    }

    memcpy(shmaddr, buf, buf_size);

    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt()");

        return (-1);
    }

    return (0);
}

int shm_read(shmid, buf, buf_size)
int shmid;
char *buf;
int buf_size;
{
    char *shmaddr;

    shmaddr = shmat(shmid, (char *)0, 0);

    if (shmaddr == (char *)-1)
    {
        perror("shmat()");

        return (-1);
    }

    memcpy(buf, shmaddr, buf_size);

    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt()");

        return (-1);
    }

    return (0);
}

int shm_lock(shmid)
int shmid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    if (shmstat.shm_perm.mode & SHM_DEST)
    {
        fprintf(stderr, "shm is destroyed\n");

        return (-1);
    }

    if (shmstat.shm_perm.mode & SHM_LOCKED)
    {
        fprintf(stderr, "shm is already locked\n");

        return (-1);
    }

    shmstat.shm_perm.mode |= SHM_LOCKED;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_unlock(shmid)
int shmid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    if (shmstat.shm_perm.mode & SHM_DEST)
    {
        fprintf(stderr, "shm is destroyed\n");

        return (-1);
    }

    if (!(shmstat.shm_perm.mode & SHM_LOCKED))
    {
        fprintf(stderr, "shm is not locked\n");

        return (-1);
    }

    shmstat.shm_perm.mode &= ~SHM_LOCKED;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_getsize(shmid, size)
int shmid;
int *size;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *size = shmstat.shm_segsz;

    return (0);
}

int shm_getmode(shmid, mode)
int shmid;
int *mode;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *mode = shmstat.shm_perm.mode;

    return (0);
}

int shm_getowner(shmid, owner)
int shmid;
int *owner;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *owner = shmstat.shm_perm.uid;

    return (0);
}

int shm_getgroup(shmid, group)
int shmid;
int *group;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *group = shmstat.shm_perm.gid;

    return (0);
}

int shm_getatime(shmid, atime)
int shmid;
time_t *atime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *atime = shmstat.shm_atime;

    return (0);
}

int shm_getctime(shmid, ctime)
int shmid;
time_t *ctime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *ctime = shmstat.shm_ctime;

    return (0);
}

int shm_getmtime(shmid, mtime)
int shmid;
time_t *mtime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *mtime = shmstat.shm_dtime;

    return (0);
}

int shm_getpid(shmid, pid)
int shmid;
int *pid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *pid = shmstat.shm_lpid;

    return (0);
}

int shm_getcuid(shmid, cuid)
int shmid;
int *cuid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *cuid = shmstat.shm_cuid;

    return (0);
}

int shm_getcgid(shmid, cgid)
int shmid;
int *cgid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *cgid = shmstat.shm_cgid;

    return (0);
}

int shm_getseq(shmid, seq)
int shmid;
int *seq;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    *seq = shmstat.shm_nattch;

    return (0);
}

int shm_setmode(shmid, mode)
int shmid;
int mode;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_perm.mode = mode;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setowner(shmid, owner)
int shmid;
int owner;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_perm.uid = owner;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setgroup(shmid, group)
int shmid;
int group;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_perm.gid = group;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setatime(shmid, atime)
int shmid;
time_t atime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_atime = atime;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setctime(shmid, ctime)
int shmid;
time_t ctime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_ctime = ctime;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setmtime(shmid, mtime)
int shmid;
time_t mtime;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_dtime = mtime;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setpid(shmid, pid)
int shmid;
int pid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_lpid = pid;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setcuid(shmid, cuid)
int shmid;
int cuid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_cuid = cuid;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setcgid(shmid, cgid)
int shmid;
int cgid;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_cgid = cgid;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_setseq(shmid, seq)
int shmid;
int seq;
{
    struct shmid_ds shmstat;

    if (shmctl(shmid, IPC_STAT, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    shmstat.shm_nattch = seq;

    if (shmctl(shmid, IPC_SET, &shmstat) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}