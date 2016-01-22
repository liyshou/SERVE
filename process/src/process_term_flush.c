#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc,char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"usage : %s file return | exit | _exit\n",argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1],"w");
    char *str = "helloworld";
    fprintf(fp,"%s",str);
    if(!strcmp(argv[2],"return"))
    {
        return 0;
    }else if(!strcmp(argv[2],"exit"))
    {
        exit(0);
    }else if(!strcmp(argv[2],"_exit"))
    {
        _exit(0);
    }
    else 
    {
        printf("process error\n");
    }
    return 0;
}
