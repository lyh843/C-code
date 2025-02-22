#include<stdio.h>
#define N 1000 //len of the arr
int arr[N] = {0};
int len_arr = 0, num_op = 0;
int f_bsearch(int number)
{
    int start = 0, end = len_arr - 1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(number < arr[mid])
        {
            end = mid - 1;
        }
        else if(number > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main(void)
{
    
    scanf("%d%d", &len_arr, &num_op);
    for(int i = 0; i < len_arr; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(num_op--)
    {
        int target = 0;
        scanf("%d", &target);
        int result = f_bsearch(target);
        printf("%d\n", result);
    }
}