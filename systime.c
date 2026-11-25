/* systime.c - call write() millions of times: mostly system time */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd = open("/dev/null", O_WRONLY);
    char c = 'x';

    if (fd == -1) {
        perror("open");
        return 1;
    }
    for (long i = 0; i < 50000L; i++)
        if (write(fd, &c, 1) != 1) {
            perror("write");
            return 1;
        }
    close(fd);
    printf("done: 50000 write() calls\n");
    return 0;
}
