#include <sys/resource.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT(resource)\
    query_limit(#resource,resource)

void query_limit(char *name,int res)
{
    struct rlimit limit;
    if(getrlimit(res,&limit))
    {
        fprintf(stderr,"getrlimit error %s\n",strerror(errno));
        exit(1);
    }
    printf("%15s ",name);
    if(limit.rlim_cur == RLIM_INFINITY)
    {
        printf(" soft (INFINITY)");
    }else
    {
        printf(" soft (%8ld)",limit.rlim_cur);
    }
    if(limit.rlim_max == RLIM_INFINITY)
    {
        printf(" hard (INFINITY)");
    }else
    {
        printf(" hard (%8ld)",limit.rlim_max);
    }
    printf("\n");

}

int main(void)
{
    LIMIT(RLIMIT_AS);
    LIMIT(RLIMIT_CORE);
    LIMIT(RLIMIT_CPU);
    LIMIT(RLIMIT_DATA);
    LIMIT(RLIMIT_FSIZE);
    LIMIT(RLIMIT_LOCKS);
    LIMIT(RLIMIT_MEMLOCK);
    LIMIT(RLIMIT_NOFILE);
    struct rlimit lt;
    lt.rlim_cur = 4;
    lt.rlim_max = 1024;
    if(setrlimit(RLIMIT_NOFILE,&lt))
    {
        fprintf(stderr,"setrlimit error %s\n",strerror(errno));
        exit(1);
    }
    printf("----------------------------\n");
    LIMIT(RLIMIT_NOFILE);

    FILE *fp1 = fopen("a.txt","r");
    if(fp1 == NULL)
    {
        fprintf(stderr,"file:%s\n",strerror(errno));
        exit(1);
    }else 
    {
        printf("open sucessed\n");
    }

    FILE *fp2 = fopen("a.txt","r");
    if(fp2 == NULL)
    {
        fprintf(stderr,"file:%s\n",strerror(errno));
        exit(1);
    }else 
    {
        printf("open sucessed\n");
    }
    return 0;
}
