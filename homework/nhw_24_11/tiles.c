#include<stdio.h>

int f_count(int num)
{
    if(num == 1 || num == 2)
    {
        return num;
    }
    else
    {
        return f_count(num - 1) + f_count(num - 2);
    }
}

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    printf("%d", f_count(num));
}