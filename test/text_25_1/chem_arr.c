#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct node 
{
    int data;
    struct node *next;
    struct node *pres;
} Node;

typedef struct step
{
    int len;
    Node *head;
    Node *tail;
} Step;

int amount_step, times;
Step *step;

int judge1(int x, int y)
{
    if(x == y)
    {
        return 0;
    }
    if(x < 1 || x > amount_step || y < 1 || y > amount_step)
    {
        return 0;
    }
    return 1;
}

void f_front()
{
    int x = 0, y = 0;
    scanf("%d%d", &x, &y);
    if(judge1(x, y))
    {
        if(step[y - 1].len != 0 && step[x - 1].len != 0)
        {
            step[y - 1].tail->next = step[x - 1].head;
            step[x - 1].head->pres = step[y - 1].tail;
            step[x - 1].head = step[y - 1].head;
            step[x - 1].len += step[y - 1].len;
            step[y - 1] = (Step){0, NULL, NULL};
        }
        else if(step[x - 1].len == 0)
        {
            step[x - 1].head = step[y - 1].head;
            step[x - 1].tail = step[y - 1].tail;
            step[x - 1].len += step[y - 1].len;
            step[y - 1] = (Step){0, NULL, NULL};
        }
    }
    return;
}

void f_back()
{
    int x = 0, y = 0;
    scanf("%d%d", &x, &y);
    if(judge1(x, y))
    {
        if(step[x - 1].len != 0 && step[y - 1].len != 0)
        {
            step[x - 1].tail->next = step[y - 1].head;
            step[y - 1].head->pres = step[x - 1].tail;
            step[x - 1].tail = step[y - 1].tail;
            step[x - 1].len += step[y - 1].len;
            step[y - 1] = (Step){0, NULL, NULL};
        }
        else if(step[x - 1].len == 0)
        {
            step[x - 1].head = step[y - 1].head;
            step[x - 1].tail = step[y - 1].tail;
            step[x - 1].len += step[y - 1].len;
            step[y - 1] = (Step){0, NULL, NULL};
        }
    }
    return;
}

int main(void)
{
    scanf("%d%d", &amount_step, &times);
    step = (Step *)malloc(amount_step * sizeof(Step));

    for(int i = 0; i < amount_step; i++)
    {
        scanf("%d", &step[i].len);
        Node *pre = NULL;
        for(int j = 0; j < step[i].len; j++)
        {
            Node *node = (Node*)malloc(sizeof(Node));
            *node = (Node){0, NULL, NULL};
            scanf("%d", &node->data);
            if(pre)
            {
                pre->next = node;
                node->pres = pre;
                step[i].tail = node;
            }
            else
            {
                step[i].head = node;
            }
            pre = node;
        }
    }

    while(times--)
    {
        char input[20] = {0};
        memset(input, 0, sizeof(input));
        scanf("%s", input);
        if(strcmp(input, "link") == 0)
        {   
            memset(input, 0, sizeof(input));
            scanf("%s", input);
            if(strcmp(input, "front") == 0)
            {
                f_front();
            }
            else //link back
            {
                f_back();
            }
        }
    }

    for(int i = 0; i < amount_step; i++)
    {
        if(step[i].len != 0)
        {
            Node *cur = step[i].head;
            while(cur)
            {
                printf("%d ", cur->data);
                cur = cur->next;
            }
            printf("\n");
        }
    }
}