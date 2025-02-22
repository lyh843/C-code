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
struct imf_node
{
    node *last_small;
    node *last_big;
    node *head;
    node *tail;
    int num_node;
    node *current;
}imf_node;

void f_add(char word[2])
{
    if(imf_node.num_node == 0)
    {
        string[0].content = word[0];
        imf_node.head = &string[0];
        imf_node.tail = &string[0];
    }
    else
    {
        string[imf_node.num_node].content = word[0];
        string[imf_node.num_node].last = imf_node.tail;
        string[imf_node.num_node].last->next = &string[imf_node.num_node];
        imf_node.tail = &string[imf_node.num_node];
    }
    if(word[0] >= 'a' && word[0] <= 'z')
    {
        string[imf_node.num_node].type = false;
        imf_node.current = &string[imf_node.num_node];
        imf_node.last_small = &string[imf_node.num_node];
        for(int i = imf_node.num_node; i >= 0; i--)
        {
            imf_node.current = imf_node.current->last;
            if(imf_node.current != NULL && imf_node.current->type == false)
            {
                string[imf_node.num_node].last_same = imf_node.current;
                break;
            }
        }
    }
    else if(word[0] >= 'A' && word[0] <= 'Z')
    {
        string[imf_node.num_node].type = true;
        imf_node.current = &string[imf_node.num_node];
        imf_node.last_big = &string[imf_node.num_node];
        for(int i = imf_node.num_node; i >= 0; i--)
        {
            imf_node.current = imf_node.current->last;
            if(imf_node.current != NULL && imf_node.current->type == true)
            {
                string[imf_node.num_node].last_same = imf_node.current;
                break;
            }
            else if(imf_node.current == NULL)
            {
                break;
            }
        }
    }
    imf_node.num_node++;
}
void f_delete_small()
{
    node *target = imf_node.last_small;
    if(target == NULL)
    {

    }
    else
    {
        imf_node.last_small = target->last_same;
        if(target->last != NULL)
        {
            target->last->next = target->next;
        }
        if(target->next != NULL)
        {
            target->next->last = target->last;
        }
        if(imf_node.num_node > 0)
        {
            imf_node.num_node--;
        }
    }
    if(target == imf_node.tail && target->last != NULL)
    {
        imf_node.tail = target->last;
    }
}
void f_delete_big()
{
    node *target = imf_node.last_big;
    if(target == NULL)
    {

    }
    else
    {
        imf_node.last_big = target->last_same;
        if(target->last != NULL)
        {
            target->last->next = target->next;
        }
        if(target->next != NULL)
        {
            target->next->last = target->last;
        }
        if(imf_node.num_node > 0)
        {
            imf_node.num_node--;
        }
    }
    if(target == imf_node.tail && target->last != NULL)
    {
        imf_node.tail = target->last;
    }
}
void f_op(char input[M])
{
    int len = 0;
    len = strlen(input);
    for(int i = 0; i < len; i++)
    {
        char word[2];
        strncpy(word, input + i, 1);
        if(word[0] == 'm')
        {
            f_delete_small();
        }
        else if(word[0] == 'M')
        {
            f_delete_big();
        }
        else
        {
            f_add(word);
        }
    }
}
void f_output(int num_output)
{
    imf_node.current = imf_node.head;
    for(int i = 0; i < num_output; i++)
    {
        printf("%c", imf_node.current->content);
        imf_node.current = imf_node.current->next;
    }
    printf("\n");
}
int main(void)
{
    int times = 0;
    scanf("%d", &times);
    while(times--)
    {
        char input[M] = {0};
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