#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define M 100 //节点个数
typedef struct Node
{
    int id;
    int size;
    struct Node *next;
}Node;
Node node[M];
struct linked
{
    int num_node;
    Node *head;
    Node *current;
}linked;
int times;
void f_init()
{
    linked.num_node = 1;
    node[linked.num_node].id = 0;
    scanf("%d%d", &node[linked.num_node].size, &times);
    linked.head = &node[linked.num_node];
}
void f_q()
{
    printf("%d\n", linked.num_node);
    linked.current = linked.head;
    for(int i = 0; i < linked.num_node; i++, linked.current = linked.current->next)
    {
        printf("%d ", linked.current->id);
    }
    printf("\n");
}
void f_size(int *size)
{
    for(int i = 0; i < 31; i++)
    {
        if(*size <= (int)pow(2, i))
        {
            *size = i;
            break;
        }
    }
}
bool f_find(int size)
{
    linked.current = linked.head;
    for(int i = 0; i < linked.num_node; i++, linked.current = linked.current->next)
    {
        if(linked.current->size == size && linked.current->id == 0)
        {
            return true;
        }
    }
    return false;
}
void f_break(int size)
{
    for(int i = 1; i < 31; i++)//需要补的空间
    {
        if(f_find(size + i))
        {
            linked.num_node++;
            node[linked.num_node].size = linked.current->size - 1;
            node[linked.num_node].next = linked.current->next;
            linked.current->size--;
            linked.current->next = &node[linked.num_node];
            break;
        }
    }
}
void f_a()
{
    int id = 0, size = 0;
    scanf("%d%d", &id, &size);
    f_size(&size);
    while(!f_find(size))
    {
        f_break(size);
    }
    linked.current->id = id;
}
int main(void)
{
    f_init();
    while(times--)
    {
        char op = 0;
        scanf("%s", &op);
        if(op == 'Q')
        {
            f_q();
        }
        else if(op == 'A')
        {
            f_a();
        }
    }
}