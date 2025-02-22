#include<stdio.h>
#include<string.h>
#define B 2000 //每个节点存储的数据
#define M 10000//组的个数
#define N 100001//输入字符串的大小
typedef struct node
{
    char content[B];
    int num_content;
    struct node *next;
}node;
struct linked
{
    node *head;
    int num_node;
}linked;
node group[M];
int num_column, times_op;
void f_input()
{
    scanf("%d%d", &num_column, &times_op);
    getchar();
    linked.num_node = 1;
    for(int i = 0; i < num_column; i++)
    {
        group[linked.num_node].content[i % B] = getchar();
        group[linked.num_node].num_content++;
        if((i % B) == (B - 1))
        {
            group[linked.num_node].next = &group[linked.num_node + 1];
            linked.num_node++;
        }
    }
    linked.head = &group[1];
}
void f_ques()
{
    int loc = 0;
    scanf("%d", &loc);
    node *current = linked.head;
    while(loc > B)
    {
        loc -= current->num_content;
        current = current->next;
    }
    while(loc > current->num_content)
    {
        loc -= current->num_content;
        current = current->next;
    }
    printf("%c\n", current->content[loc - 1]);
}
void f_devide(node *current, int loc)
{
    linked.num_node++;
    strcpy(group[linked.num_node].content, current->content + loc);
    group[linked.num_node].num_content = current->num_content - loc;
    current->num_content = loc;
    group[linked.num_node].next = current->next;
    current->next = &group[linked.num_node];
}
void f_add(char string[N], node* current)
{
    int len = strlen(string);
    int temp_num_node = ++linked.num_node;
    for(int i = 0; i < len; i++)
    {
        group[linked.num_node].content[i % B] = string[i];
        group[linked.num_node].num_content++;
        if((i % B) == (B - 1))
        {
            group[linked.num_node].next = &group[linked.num_node + 1];
            linked.num_node++;
        }
    }
    if(current->next->num_content + group[linked.num_node].num_content <= B)
    {
        strcpy(group[linked.num_node].content + group[linked.num_node].num_content, current->next->content);
        group[linked.num_node].next = current->next->next;
        group[linked.num_node].num_content = current->next->num_content + group[linked.num_node].num_content;
    }
    else
    {
        group[linked.num_node].next = current->next;
    }
    if(current->num_content + group[temp_num_node].num_content <= B)
    {
        strcpy(current->content + current->num_content, group[temp_num_node].content);
        current->next = group[temp_num_node].next;
        current->num_content = current->num_content + group[temp_num_node].num_content;
    }
    else
    {
        current->next = &group[temp_num_node];
    }
}
void f_in()
{
    int loc = 0;
    char string[N] = {0};
    scanf("%d%s", &loc, string);
    node *current = linked.head;
    while(loc > B)
    {
        loc -= current->num_content;
        current = current->next;
    }
    while(loc > current->num_content)
    {
        loc -= current->num_content;
        current = current->next;
    }
    f_devide(current, loc);
    f_add(string, current);
}
int main(void)
{
    f_input();
    while(times_op--)
    {
        char op[2] = {0};
        scanf("%s", op);
        if(op[0] == 'Q')
        {
            f_ques();
        }
        else if(op[0] == 'I')
        {
            f_in();
        }
    }
}