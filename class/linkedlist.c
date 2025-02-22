#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *next;
} node;
struct
{
    node *head;
    node *tail;
}linkedlist;
node *f_create(int data) //创建一个新的节点
{
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Error: fail to malloc!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void f_add_head(int data)//在首位添加节点
{
    node *newnode = f_create(data);
    newnode->next = linkedlist.head;
    linkedlist.head = newnode;
}
void f_add_tail(int data)//在末尾添加节点
{
    node *newnode = f_create(data);
    if(linkedlist.head == NULL)
    {
        linkedlist.head = newnode;
    }
    else
    {
        node *current = linkedlist.head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}
void f_add(int data, int position)//在指定位置插入节点
{
    if(position == 0)
    {
        f_add_head(data);
    }
    else
    {
        node *newnode = f_create(data);
        node *current = linkedlist.head;
        for(int i = 0; i < position - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if(current == NULL)
        {
            printf("The position does not exist!\n");
        }
        else
        {
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}
void *f_delete()
{
    if(linkedlist.head == NULL)//空链表
    {
        printf("Empty\n");
    }
    if(linkedlist.head == linkedlist.tail)//单个元素
    {
        free(linkedlist.head);
        linkedlist.head = NULL;
        linkedlist.tail = NULL;
    }
    node *current = linkedlist.head;
    while(current->next != linkedlist.tail)
    {
        current = current->next;
    }
    free(linkedlist.tail);
    linkedlist.tail = current;
    linkedlist.tail->next = NULL;
}
void f_find(int target)
{
    
}
int main(void)
{
    int data = 1234;
    f_create(data);
    for(int i = 0 ; i < 10; i++)
    {
        f_add(i);
    }
    int input = 0;
    scanf("%d", &input);
    f_find(input);
}