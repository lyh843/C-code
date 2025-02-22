#include<stdio.h>
#include<stdlib.h>
#define N 5005 //num of used

typedef struct node
{
    int l;
    int r;
    struct node *next;
}node;

typedef struct usednode
{
    int l; 
    int r;
}usednode;
usednode *use[N];

node *head;
int id = 0;

void f_init(int size)
{
    head = malloc(sizeof(node));
    head->l = 0;
    head->r = 0;
    head->next = malloc(sizeof(node));
    head->next->l = 0;
    head->next->r = size;
    head->next->next = NULL;
}

void f_create()
{
    id++;
    int size = 0;
    scanf("%d", &size);
    node *p = head;
    while(p->next != NULL)
    {
        if(p->next->r - p->next->l >= size)
        {
            break;
        }
        p = p->next;
    }
    int left = 0;
    if(p->next != NULL)
    {
        if(p->next->r - p->next->l == size)
        {
            left = p->next->l;
            node *tofree = p->next;
            p->next = p->next->next;
            free(tofree);
        }
        else
        {
            left = p->next->l;
            p->next->l = p->next->l + size;
        }
        use[id] = malloc(sizeof(usednode));
        use[id]->l = left;
        use[id]->r = left + size;
        printf("%d\n", left);
    }
    else
    {
        printf("malloc fail\n");
    }
}

void f_merge()
{
    node *p = head;
    while(p->next != NULL && p->next->next != NULL)
    {
        if(p->next->r == p->next->next->l)
        {
            node *tofree = p->next;
            p->next->next->l = p->next->l;
            p->next = p->next->next;
            free(tofree);
        }
        else
        {
            p = p->next;
        }
    }
}

void f_delete()
{
    int de_id = 0;
    scanf("%d", &de_id);
    if(use[de_id])
    {
        node *p = head;
        while(p->next != NULL)
        {
            if(p->next->l >= use[de_id]->r)
            {
                break;
            }
            p = p->next;
        }
        if(p->next == NULL)
        {
            p->next = malloc(sizeof(node));
            p->next->l = use[de_id]->l;
            p->next->r = use[de_id]->r;
            p->next->next = NULL;
        }
        else
        {
            node *newnode = malloc(sizeof(node));
            newnode->l = use[de_id]->l;
            newnode->r = use[de_id]->r;
            newnode->next = p->next;
            p->next = newnode;
        }
        f_merge();
        free(use[de_id]);
        use[de_id] = NULL; 
        printf("free success\n");
    }
    else
    {
        printf("free fail\n");
    }
}

void f_ques()
{
    node *p = head;
    p = p->next;
    if(p == NULL)
    {
        printf("NULL\n");
        return ;
    }
    while(p != NULL)
    {
        printf("[%d,%d) ", p->l, p->r);
        if(p->next == NULL)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }
    printf("\n");
}
int main(void)
{
    int times = 0, size = 0;
    scanf("%d%d", &times, &size);
    f_init(size);
    while(times--)
    {
        int op = 0;
        scanf("%d", &op);
        if(op == 1)
        {
            f_create();
        }
        else if(op == 2)
        {
            f_delete();
        }
        else if(op == 3)
        {
            f_ques();
        }
    }
}