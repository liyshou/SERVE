#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void m_system(char *cmd)
{
    pid_t pid;
    pid = vfork();
    if(pid < 0)
    {
        fprintf(stderr,"vfork error %s\n",strerror(errno));
        exit(1);
    }
    else if(pid == 0)
    {
        execl("/bin/bash","bash","-c",cmd,NULL);
    }else
    {
        wait(0);
    }
}

int main(void)
{
    m_system("cat /etc/passwd");
    printf("------------------------------------------\n");
    m_system("cat /etc/passwd | grep root");
    return 0;
}
