#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        fprintf(stderr,"fork error %s\n",strerror(errno));
        exit(1);
    }else if(pid > 0)
    {
        while(1)
        {
            sleep(3);
        }
        printf("parent pid: %d,ppid: %d\n",getpid(),getppid());
    }
    else
    {
        printf("child pid: %d,ppid: %d\n",getpid(),getppid());
        exit(1);
    }
    return 0;
}
