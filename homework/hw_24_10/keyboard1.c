#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define M 100 //字符串的总数
typedef struct node
{
    char content;
    bool type; //true 大写， false小写
    struct node *last;
    struct node *next;
    struct node *last_same;
}node;
node string[M];
int num_node = 0;//序号而已，没啥用
struct imf_node
{
    node *last_small;
    node *last_big;
    node *head;
    node *tail;
    int amount_node;//存活节点的总数
    node *current;
}imf_node;
char output[M] = {0};
char input[M] = {0};
void f_add(char word)
{
    string[num_node].content = word;

    if(imf_node.amount_node == 0)
    {
        imf_node.head = &string[num_node];
        imf_node.tail = &string[num_node];
    }
    else
    {
        imf_node.tail->next = &string[num_node];
        string[num_node].last = imf_node.tail;
        string[num_node].next = NULL;
        imf_node.tail = &string[num_node];
    }

    if(word >= 'a' && word <= 'z')
    {
        string[num_node].type = false;
        string[num_node].last_same = imf_node.last_small;
        imf_node.last_small = &string[num_node];
    }
    else if(word >= 'A' && word <= 'Z')
    {
        string[num_node].type = true;
        string[num_node].last_same = imf_node.last_big;
        imf_node.last_big = &string[num_node];
    }
    num_node++;
    imf_node.amount_node++;
}

void f_delete_small()
{
    if(imf_node.amount_node != 0 && imf_node.last_small != NULL)
    {
        if(imf_node.last_small == imf_node.tail)
        {
            imf_node.tail = imf_node.last_small->last;
        }
        if(imf_node.last_small->last != NULL)
        {
            imf_node.last_small->last->next = imf_node.last_small->next;
        }
        if(imf_node.last_small->next != NULL)
        {
            imf_node.last_small->next->last = imf_node.last_small->last;
        }
        imf_node.last_small = imf_node.last_small->last_same;
        imf_node.amount_node--;
    }
}

void f_delete_big()
{
    if(imf_node.amount_node != 0 && imf_node.last_big != NULL)
    {
        if(imf_node.last_big == imf_node.tail)
        {
            imf_node.tail = imf_node.last_big->last;
        }
        if(imf_node.last_big->last != NULL)
        {
            imf_node.last_big->last->next = imf_node.last_big->next;
        }
        if(imf_node.last_big->next != NULL)
        {
            imf_node.last_big->next->last = imf_node.last_big->last;
        }
        imf_node.last_big = imf_node.last_big->last_same;
        imf_node.amount_node--;
    }
}

void f_output(int num_output)
{
    imf_node.current = imf_node.tail;
    for(int i = 0; i < num_output; i++)
    {
        output[num_output - i - 1] = imf_node.current->content;
        imf_node.current = imf_node.current->last;
    }
    output[num_output] = 0;
    printf("%s\n", output);
}

void f_op(char input[M])
{
    int len = 0;
    len = strlen(input);
    for(int i = 0; i < len; i++)
    {
        char word = input[i];
        if(word == 'm')
        {
            f_delete_small();
        }
        else if(word == 'M')
        {
            f_delete_big();
        }
        else
        {
            f_add(word);
        }
    }
}

int main(void)
{
    int times = 0;
    scanf("%d", &times);
    while(times--)
    {
        scanf("%s", input);
        if(strcmp(input, "?") == 0)
        {
            int num_output = 0;
            scanf("%d", &num_output);
            f_output(num_output);
        }
        else
        {
            f_op(input);
        }
    }
    return 0;
}