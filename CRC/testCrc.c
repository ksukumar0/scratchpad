#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("input.txt", O_RDONLY);
    close(fd);
    return 0;
}
