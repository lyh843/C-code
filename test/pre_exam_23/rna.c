#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define N 10004 //字符串开的大小
#define M 500  //命令的数量

typedef struct Node
{
    char c;
    struct Node *next;
}node;

typedef struct List
{
    node *head;
    node *tail;
}List;

List main_list;

typedef struct Rule
{
    char *s, *t;
}rule;

int amount_rule, times;
rule r[M];

List f_create(char *str)
{
    List list;
    node *newnode = (node *)malloc(sizeof(node));
    list.head = newnode;
    char *ptr = str;
    while(1)
    {
        newnode->c = *ptr;
        ptr++;
        if(*ptr == '\0')
        {
            list.tail = newnode;
            break;
        }
        newnode->next = (node *)malloc(sizeof(node));
        newnode = newnode->next;
    }
    return list;
}

void f_input()
{
    char *str = (char *)malloc(N * sizeof(char));
    scanf("%s", str + 1);
    main_list = f_create(str);
    scanf("%d%d", &amount_rule, &times);
    for(int i = 0; i <= amount_rule; i++)
    {
        r[i].s = (char *)malloc(N * sizeof(char));
        r[i].t = (char *)malloc(N * sizeof(char));
        scanf("%s%s", r[i].s, r[i].t);
    }
}

void delete(node *s, int len)
{
    while(len--)
    {
        node *cur = s;
        s = s->next;
        free(cur);
    }
}

void f_op(int num_rule)
{
    node *cur = main_list.head;
    int len_s = strlen(r[num_rule].s);
    while(cur != NULL)
    {
        bool findout = false;
        node *p1 = cur->next;
        char *ptr = r[num_rule].s;
        while(p1 != NULL)
        {
            if(*ptr == '\0')
            {
                break;
            }
            if(p1->c != *ptr)
            {
                break;
            }
            p1 = p1->next;
            ptr++;
        }
        findout = !*ptr;
        if(findout)
        {
            List list_t = f_create(r[num_rule].t);
            delete(cur->next, len_s);
            cur->next = list_t.head;
            list_t.tail->next = p1;
            cur = list_t.tail;
        }
        else
        {
            cur = cur->next;
        }
    }
}

void f_print()
{
    node *cur = main_list.head;
    while(cur)
    {
        printf("%c", cur->c);
        cur = cur->next;
    }
    printf("\n");
}

int main(void)
{
    f_input();
    while(times--)
    {
        for(int i = 0; i < amount_rule; i++)
        {
            f_op(i);
        }
    }
    f_print();
    return 0;
}