#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct linkedlist 
{
    struct node *head;
    struct node *tail;
};

// 根据data初始化一个结点
struct node* initNode(int data)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

// 插入至链表的末尾
void insertAtTail(struct linkedlist *ll, struct node *newnode)
{
    if (ll->head == NULL) 
    {
        ll->head = newnode;
        ll->tail = newnode;
    } 
    else 
    {
        ll->tail->next = newnode;
        ll->tail = newnode;
    }
}

// 插入至链表的开头
void insertAtHead(struct linkedlist *ll, struct node *newnode) 
{
    if (ll->head == NULL) 
    {
        ll->head = newnode;
        ll->tail = newnode;
    } 
    else 
    {
        newnode->next = ll->head; // newnode的next指针指向头结点
        ll->head = newnode; // 更新链表的头结点
    }
}

// 按升序插入至链表
void insertSortedAscending(struct linkedlist *ll, struct node *newnode)
{

}

// 按降序插入至链表
void insertSortedDescending(struct linkedlist *ll, struct node *newnode)
{
}

void delete(struct linkedlist *ll, int value) 
{
    struct node *curr = ll->head;
    struct node *prev = curr;
    int flag = 0;
    while (curr != NULL) 
    {
        if (curr->data == value) 
        {
            printf("find a node with data equals to value\n");
            flag = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("flag: %d\nprev: %p, curr: %p\n", flag, prev, curr);
    if (flag == 1) 
    {
        if (curr == ll->head) 
        {
            ll->head = curr->next;
            free(curr);
        } 
        else 
        {
            prev->next = curr->next;
            free(curr);
        }
    }
}

void display(struct linkedlist *ll)
{
    struct node *p = ll->head;
    while (p != ll->tail) 
    {
        //printf("%p: (%d, %p)\n", p, p->data, p->next);
        printf("%d ", p->data);
        p = p->next;
    }
    //printf("%p: (%d, %p)\n\n", p, p->data, p->next);
    printf("%d ", p->data);
}


int main()
{
    struct linkedlist ll = {NULL, NULL};
    struct node *p;
    for (int i = 0; i < 10; ++i) 
    {
        p = initNode(i);
        insertAtTail(&ll, p);
    }
    display(&ll);
    p = initNode(11);
    insertAtHead(&ll, p);
    display(&ll);
    delete(&ll, 6);
    display(&ll);
    return 0;
}