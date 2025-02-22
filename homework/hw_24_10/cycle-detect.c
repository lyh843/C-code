#include<stdio.h>
#include<stdbool.h>
#define M 100//结点个数
#define N 30//字符串长度
typedef struct
{
    char string[N];
    long long target;
}t_node;
t_node node[M];
int num_node = 0;
int f_detection()
{
    int arr[M] = {0};
    arr[1]++;
    int current = 1;
    for(int i = 2; i <= num_node + 1; i++)
    {
        current = node[current].target;
        arr[current]++;
        if(arr[current] == 2)
        {
            printf("%s", node[current].string);
            break;
        }
    }
    return 0;
}
int main(void)
{
    scanf("%d", &num_node);
    for(int i = 1; i <= num_node; i++)
    {
        scanf("%s", node[i].string);
        int number = 0;
        scanf("%d", &number);
        if(number < 1 || number > num_node)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            node[i].target = number;
        }
    }
    f_detection();
}