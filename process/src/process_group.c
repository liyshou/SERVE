#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    pid_t pid;
    int i = 0;
    pid_t group1;
    pid_t group2;
    setpgid(getpid(),getpid());
    group1 = getpgid(getpid());
    for(i;i < 3;i++)
    {
        pid = fork();
        if(pid < 0)
        {
            fprintf(stderr,"fork error:%s\n",strerror(errno));
            exit(1);
        }
        else if(pid > 0) //parent process
        {
            if (i == 0)
            {
                setpgid(pid,group1);
            }
            if (i == 1)
            {
                setpgid(pid,pid);
                group2 = getpgid(pid);
            }
            if (i == 2)
            {
                setpgid(pid,group2);
            }
        }else           //child process
        {
            if(i == 0)
            {
                setpgid(getpid(),group1);
            }

            if(i == 1)
            {
                setpgid(getpid(),getpid());
                group2 = getpgid(getpid());
            }
            if(i == 2)
            {
                setpgid(getpid(),group2);
            }
            break;
        }
    }

    printf("pid: %d,ppid: %d,groupid: %d\n",getpid(),getppid(),getpgid(0));
    sleep(2);
    return 0;
}
