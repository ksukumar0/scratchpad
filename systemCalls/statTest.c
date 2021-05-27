#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);

    printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);

    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    int retvalw = access(argv[1], W_OK);
    int retvalr = access(argv[1], R_OK);

    printf("Value of AccessW:          %d\n",retvalw);
    printf("Value of AccessR:          %d\n",retvalr);

    if( (access(argv[1], W_OK) == -1) && (access(argv[1], R_OK) == 0))
    {
        printf("Read Only File\n");
    }


    bool bReturn = true;
    if( (access(argv[1], W_OK) == -1) && (access(argv[1], R_OK) == 0) )
    {
        // open File and flush to disk
        int fd = open(argv[1], O_RDWR);

        // Open successful
        if(fd > 0)
        {
            // Do Flush
            int dwErr = fsync(fd);
            close(fd);
            if(dwErr < 0)
            {
                bReturn = false;
            }
        }
        // Fileopen unsuccessful
        else
        {
            bReturn = false;
        }
    }

    char name[100];
    int retval = getlogin_r(name, 100);
    printf("Retval: %d and Username: %s\n",retval, name);
    if (retval == 0)
    {
        retval = logout(&name[0]);
    }
    exit(EXIT_SUCCESS);
}
