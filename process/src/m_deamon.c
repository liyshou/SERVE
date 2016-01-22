#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <syslog.h>


int main(int argc,char *argv[])
{
    umask(0000);
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        fprintf(stderr,"fork error : %s\n",strerror(errno));
        exit(1);
    }
    else if(pid > 0)
    {
        exit(1);
    }

    setsid();
    chdir("/");
    close(0);
    close(1);
    close(2);
    openlog(argv[0],LOG_PID,LOG_SYSLOG);
    char *str = "hello world";
    while(1)
    {
        syslog(LOG_DEBUG,"%s",str);
        sleep(3);
    }
    closelog();
    return 0;
}
