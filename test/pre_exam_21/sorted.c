#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 1001 //数组长度
int arr[N] = {0};//下标从1开始
bool f_judge(int len_arr)
{
    for(int i = 1; i < len_arr; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main(void)
{
    int group = 0;
    scanf("%d", &group);
    while(group--)
    {
        int len_arr = 0, num_op = 0;
        scanf("%d%d", &len_arr, &num_op);
        memset(arr, 0, N * sizeof(int));
        for(int i = 1; i <= len_arr; i++)
        {
            scanf("%d", &arr[i]);
        }
        while(num_op--)
        {
            int op = 0;
            scanf("%d", &op);
            int temp = arr[op];
            for(int i = op; i >= 2; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[1] = temp;
        }
        if(f_judge(len_arr))
        {
            printf("I love C programing language\n");
        }
        else
        {
            printf("mayi is a good teacher\n");
        }
    }
    return 0;
}