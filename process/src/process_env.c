#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;

void showenv()
{
    int i = 0;
    char *str;
    while((str = environ[i]) != NULL)
    {
        printf("%s\n",str);
        i++;
    }
}

int main(void)
{
    showenv();
    printf("----------------------------\n");
    printf("PATH:%s\n",getenv("PATH"));
    setenv("PATH",".:/bin:/usr/bin",1);
    printf("PATH:%s\n",getenv("PATH"));
    putenv("NAME=jiekexueyuan");
    printf("NAME:%s\n",getenv("NAME"));
    return 0;
}
