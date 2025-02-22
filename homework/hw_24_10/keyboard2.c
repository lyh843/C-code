#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define M 100 //字符串的总数
typedef struct node
{
    char content;
    struct node *last;
    struct node *next;
    struct node *last_same;
}node;
node string[M];
int num_node = 0;//序号而已，没啥用
char output[M] = {0};
struct imf_node
{
    node *last_small;
    node *last_big;
    node *head;
    node *tail;
    int amount_node;//存活节点的总数
    node *current;
}imf_node;
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

    if(islower(word))
    {
        string[num_node].last_same = imf_node.last_small;
        imf_node.last_small = &string[num_node];
    }
    else if(isupper(word))
    {
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

void f_op(char input)
{
    if(input != 'm' && input != 'M')
    {
        f_add(input);
    }
    else if(input == 'M')
    {
        f_delete_big();
    }
    else
    {
        f_delete_small();
    }
}

int main(void)
{
    int times = 0;
    scanf("%d", &times);
    getchar();
    while(times--)
    {
        char input = getchar();
        if(input == '?')
        {
            int num_output = 0;
            scanf("%d", &num_output);
            getchar();
            f_output(num_output);
        }
        else
        {
            do
            {
                f_op(input);
                input = getchar();
            }
            while(isalpha(input));
        }
    }
    return 0;
}