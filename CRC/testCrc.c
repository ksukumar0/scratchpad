#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

extern unsigned long
calc_crc32 (unsigned long crc,
                     unsigned char *buf, size_t len);

int main(void)
{
    int fd = open("input_ascii.txt", O_RDONLY);
    char buf[10000];
    int size = read(fd, buf, 10000);
    printf("%s", buf);
    unsigned long crc = calc_crc32(0, buf, size);
    printf("0x%x\n", crc);
    close(fd);
    return 0;
}
