#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 20 //名字长度
#define M 5 //节点数量

typedef struct File
{
    char name[N];
    int amount_dir;
    struct File* dir[M];
}file;

file *root;

int amount_file, amount_op;

file *f_search(char target[N], file *current)
{
    if(strcmp(target, root->name) == 0)
    {
        return root;
    }
    for(int i = 1; i <= current->amount_dir; i++)
    {
        if(strcmp(target, current->dir[i - 1]->name) == 0)
        {
            return current->dir[i - 1];
        }   
        else if(current->dir[i - 1]->amount_dir != 0)
        {
            file *temp = f_search(target, current->dir[i - 1]);
            if(temp)
            {
                return temp;
            }
            else
            {
                continue;
            }
        }
    }
    return NULL;
}

file *f_fasearch(char target[N], file *current)
{
    for(int i = 1; i <= current->amount_dir; i++)
    {
        if(strcmp(target, current->dir[i - 1]->name) == 0)
        {
            return current;
        }   
        else if(current->dir[i - 1]->amount_dir != 0)
        {
            file *temp = f_fasearch(target, current->dir[i - 1]);
            if(temp)
            {
                return temp;
            }
            else
            {
                continue;
            }
        }
    }
    return NULL;
}

file *f_create(char name[N])
{
    file *newnode = malloc(sizeof(file));
    strcpy(newnode->name, name);
    newnode->amount_dir = 0;
    newnode->dir[0] = NULL;
    newnode->dir[1] = NULL;
}

void f_input()
{
    for(int i = 1; i <= amount_file; i++)
    {
        char newfile[N] = {0};
        char c_father[N] = {0};
        scanf("%s%s", newfile, c_father);
        if(*c_father == '~')
        {
            file *f_new = f_create(newfile);
            root = f_new;
            continue;
        }
        file *f_father = f_search(c_father, root);
        file *f_new = f_create(newfile);
        f_father->amount_dir++;
        f_father->dir[f_father->amount_dir - 1] = f_new;  
    }
}

int f_count(file *target)
{
    int count = 0;
    count += target->amount_dir;
    for(int i = 0; i < target->amount_dir; i++)
    {
        count += f_count(target->dir[i]);
    }
    return count;
}

void f_query()
{
    char c_target[N];
    scanf("%s", c_target);
    file *f_target = f_search(c_target, root);
    int result = f_count(f_target);
    printf("%d\n", result + 1);
}

void f_delete(file *target)
{
    for(int i = 0; i < target->amount_dir; i++)
    {
        f_delete(target->dir[i]);
    }
    free(target);
}

void f_remove()
{
    char c_target[N];
    scanf("%s", c_target);
    file *f_target = f_search(c_target, root);
    file *f_fa = f_fasearch(c_target, root);
    if(f_fa->dir[0] == f_target)
    {
        f_fa->amount_dir--;
        f_fa->dir[0] = f_fa->dir[1];
    }
    else
    {
        f_fa->amount_dir--;
    }
    f_delete(f_target);
}

int main(void)
{
    scanf("%d%d", &amount_file, &amount_op);
    f_input();
    while(amount_op--)
    {
        char c_op[N] = {0};
        scanf("%s", c_op);
        if(*c_op == 'q')
        {
            f_query();
        }
        else if(*c_op == 'r')
        {
            f_remove();
        }
    }
}