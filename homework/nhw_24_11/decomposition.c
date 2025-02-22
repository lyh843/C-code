#include <stdio.h>

void f_op(int n, int start, int *arr, int index)
{
    if(n == 0)
    {
        for(int i = 0; i < index; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = start; i <= n; i++)
    {
        arr[index] = i;
        f_op(n - i, i, arr, index + 1);
    }
}
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int arr[30] = {0};
    f_op(n, 1, arr, 0);
}