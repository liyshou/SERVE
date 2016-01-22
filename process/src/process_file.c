#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int fd = open("a.txt",O_RDWR);
    if(fd < 0)
    {
        fprintf(stderr,"open error %s\n",strerror(errno));
        exit(1);
    }

    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr,"fork error %s\n",strerror(errno));
        exit(1);
    }else if (pid > 0) //parent process
    {
        if(lseek(fd,0L,2) < 0)
        {
            fprintf(stderr,"lseek error %s\n",strerror(errno));
            exit(1);
        }
        close(fd);
    }
    else
    {
        sleep(3);
        char *str = "abcdefg";
        write(fd,str,strlen(str));
    }
    close(fd);
    wait(0);
    return 0;
}
