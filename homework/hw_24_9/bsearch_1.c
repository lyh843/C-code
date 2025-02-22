#include<stdio.h>
#include<stdlib.h>
#define N 100
int arr[N];
int size, times;

int cmp(const void *num1, const void *num2)
{
    int num_1 = *(int *)num1;
    int num_2 = *(int *)num2;
    if(num_1 < num_2)
    {
        return -1;
    }
    else if(num_1 > num_2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main (void)
{
    scanf("%d%d", &size, &times);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(times--)
    {
        int key = 0;
        int *result = 0;
        scanf("%d", &key);
        result = bsearch(&key, arr, size, sizeof(int), cmp);
        if(result)
        {
            printf("%d\n", result - arr);
        }
        else
        {
            printf("-1\n");
        }
    }
}