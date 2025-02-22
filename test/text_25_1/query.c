#include <stdio.h>
#include<stdlib.h>
#define N 500005 // size of arr
int arr[N];

int cmp1(const void *num1, const void *num2)
{
    int a = *(int *)num1;
    int b = *(int *)num2;
    if(a > b)
    {
        return 1;
    }
    else if(a < b)
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

int cmp2(const void* num1, const void* num2)
{
    int a = *(int *)num1;
    int b = *(int *)num2;
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main(void) 
{
    int amount = 0;
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, amount, sizeof(int), cmp1);
    int times = 0;
    scanf("%d", &times);
    while(times--)
    {
        int key = 0;
        scanf("%d", &key);
        int *result = bsearch(&key, arr, amount, sizeof(int), cmp2);
        if(result)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}