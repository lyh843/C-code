#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct Stack
{
    int num;//元素的个数
    int *arr;//含有的数字
}stack;

stack node[N];

int num_stack, times;
void f_init()
{
    for(int i = 1; i <= num_stack; i++)
    {
        node[i].num = 1;
        node[i].arr = malloc(sizeof(int));
        node[i].arr[0] = i;
    }
}

void f_op(int x, int y)
{
    if(node[y].arr)
    {
        node[y].arr = realloc(node[y].arr, (node[y].num + node[x].num) * sizeof(int));
    }
    else
    {
        node[y].arr = malloc(node[x].num * sizeof(int));
    }
    for(int i = 1; i <= node[x].num; i++)
    {
        node[y].arr[node[y].num - 1 + i] = node[x].arr[node[x].num - i];
    }
    node[y].num += node[x].num;
    node[x].num = 0;
    if(node[x].arr)
    {
        free(node[x].arr);
        node[x].arr = NULL;
    }
}

void f_print()
{
    for(int i = 1; i <= num_stack; i++)
    {
        if(node[i].num == 0)
        {
            printf("0");
        }
        else
        {
            for(int j = 1; j <= node[i].num; j++)
            {
                printf("%d ", node[i].arr[j - 1]);
            }
        }
        printf("\n");
    }
}

int main(void)
{
    scanf("%d%d", &num_stack, &times);
    f_init();
    while(times--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        f_op(x, y);
    }
    f_print();
}