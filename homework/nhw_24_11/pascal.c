#include<stdio.h>
int row, col;
int f_op(int a, int b)
{
    if(b == 0 || a == b)
    {
        return 1;
    }
    else
    {
        return f_op(a - 1, b - 1) + f_op(a - 1, b);
    }
}
int main(void)
{
    scanf("%d%d", &row, &col);
    printf("%d", f_op(row - 1, col - 1));
    return 0;
}