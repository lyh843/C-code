#include<stdio.h>
#define N 100005
int f[N];
int find(int x)
{
    if(x == f[x])
    {
        return x;
    }
    else
    {
        return find(f[x]);
    }
}
int main(void)
{
    int num = 0;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    {
        scanf("%d", &f[i]);
    }
    for(int i = 1; i <= num; i++)
    {
        printf("%d ", find(i));
    }
}