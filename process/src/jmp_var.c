#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jmp;
int g_v = 1;

void fun()
{
    longjmp(jmp,1);
}

int main(void)
{
    static int s_v = 1;
    auto int a_v = 1;
    register r_v = 1;
    volatile v_v = 1;
    int *h_v = (int*)malloc(sizeof(int));
    *h_v = 1;
    printf("g_v=%d,s_v=%d,a_v=%d,r_v=%d,v_v=%d,h_v=%d\n",g_v,s_v,a_v,r_v,v_v,*h_v);

    if(setjmp(jmp) == 1)
    {
        printf("g_v=%d,s_v=%d,a_v=%d,r_v=%d,v_v=%d,h_v=%d\n",g_v,s_v,a_v,r_v,v_v,*h_v);
        exit(1);
    }

    g_v = 10;
    s_v = 10;
    a_v = 10;
    r_v = 10;
    v_v = 10;
    *h_v = 10;
    printf("g_v=%d,s_v=%d,a_v=%d,r_v=%d,v_v=%d,h_v=%d\n",g_v,s_v,a_v,r_v,v_v,*h_v);
    fun();
    return 0;
}
