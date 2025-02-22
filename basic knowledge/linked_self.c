#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;

struct linkedlist 
{
    node *head;
    node *tail;
}linkedlist;


// 根据data初始化一个结点
node* initNode(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// 插入至链表的末尾
void insertAtTail(struct linkedlist *ll, struct node *newnode)
{
    if(linkedlist.tail)
    {
        linkedlist.tail->next = newnode;
        linkedlist.tail = newnode;
    }
    else
    {
        linkedlist.head = newnode;
        linkedlist.tail = newnode;
    }
}

// 插入至链表的开头
void insertAtHead(struct linkedlist *ll, struct node *newnode) 
{
    if(linkedlist.head)
    {
        newnode->next = linkedlist.head;
        linkedlist.head = newnode;
    }
    else
    {
        linkedlist.head = newnode;
        linkedlist.tail = newnode;
    }
}

// 按升序插入至链表
void insertSortedAscending(struct linkedlist *ll, struct node *newnode)
{
    if(linkedlist.head)
    {
        node *cur = linkedlist.head;
        node *pre = cur;
        if(newnode->data <= cur->data)
        {
            newnode->next = cur;
            linkedlist.head = newnode;
        }
        while(cur != NULL)
        {
            if(pre->data <= newnode->data && newnode->data <= cur->data)
            {
                pre->next = newnode;
                newnode->next = cur;
                break;
            }
            if(cur == linkedlist.tail)
            {
                cur->next = newnode;
                linkedlist.tail = newnode;
            }
        }
    }
    else
    {
        linkedlist.head = newnode;
        linkedlist.tail = newnode;
    }
}

// 按降序插入至链表
void insertSortedDescending(struct linkedlist *ll, struct node *newnode)
{
}

void delete(struct linkedlist *ll, int value) 
{
    node *cur = linkedlist.head;
    node *pre = cur;
    while(cur != NULL)
    {
        if(cur->data == value)
        {
            cur = cur->next;
            free(pre->next);
            pre->next = cur;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

void display(struct linkedlist *ll)
{

}


int main()
{
    return 0;
}