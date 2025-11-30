#include <stdio.h>

// 全局变量
int c = 0;
void counter()
{
    static int c = 0;
    c++;
    printf("c = %d\n", c);
}

int main()
{
    counter();
    counter();
    counter();
    return 0;
}