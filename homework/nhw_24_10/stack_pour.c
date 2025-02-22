#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int num;//元素的个数
    int *arr;//含有的数字
    struct Stack *next;//下一个栈
}stack;

int num_stack, times;
stack *head;
void f_init()
{
    stack *cur = malloc(sizeof(stack));
    head = cur;
    stack *pre = cur;
    cur->num = 1;
    cur->arr = malloc(cur->num * sizeof(int));
    cur->arr[0] = 1;
    for(int i = 2; i <= num_stack; i++)
    {
        cur = malloc(sizeof(stack));
        cur->num = 1;
        cur->arr = malloc(cur->num * sizeof(int));
        cur->arr[0] = i;
        pre->next = cur;
        pre = cur;
    }
}

stack *f_match(int target)
{
    stack *cur = head;
    for(int i = 2; i <= target; i++)
    {
        cur = cur->next;
    }
    return cur;
}

void f_op(int x, int y)
{
    stack *p1 = f_match(x);
    stack *p2 = f_match(y);
    if(p2->arr)
    {
        p2->arr = realloc(p2->arr, (p2->num + p1->num) * sizeof(int));
    }
    else
    {
        p2->arr = malloc(p1->num * sizeof(int));
    }
    for(int i = 1; i <= p1->num; i++)
    {
        p2->arr[p2->num - 1 + i] = p1->arr[p1->num - i];
    }
    p2->num += p1->num;
    p1->num = 0;
    if(p1->arr)
    {
        free(p1->arr);
        p1->arr = NULL;
    }
}

void f_print()
{
    stack *cur = head;
    for(int i = 1; i <= num_stack; i++)
    {
        if(cur->num == 0)
        {
            printf("0");
        }
        else
        {
            for(int j = 1; j <= cur->num; j++)
            {
                printf("%d ", cur->arr[j - 1]);
            }
        }
        printf("\n");
        cur = cur->next;
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