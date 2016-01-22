#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    pid = vfork();
    if(pid < 0)
    {
        fprintf(stderr,"vfork error :%s\n",strerror(errno));
        exit(1);
    }
    else if(pid == 0)
    {
        char *argv[] = {"cat","/etc/passwd",NULL};
        char *env[] = {"PAHT = /bin","SHELL = bash",NULL};
        execve("/bin/cat",argv,env);
    }
    else
    {
        wait(0);
    }
    printf("pid : %d,ppid: %d\n",getpid(),getppid());
    return 0;
}
