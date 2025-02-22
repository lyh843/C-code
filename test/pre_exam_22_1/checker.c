#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define N 100 //字符串长度
char string[N] = {0};
char string1[N] = {0};
int count[100] = {0};
int arr[100] = {0};
int num_wrong = 0;
int len = 0;
bool f_judge1()
{
    for(int i = 0; i < strlen(string1); i++)
    {
        if(string1[i] != string1[strlen(string1) - 1 - i])
        {
            return false;
        }
    }
    return true;
}
bool f_spejudge()
{
    for(int i = 0; i < strlen(string1); i++)
    {
        if(isdigit(string1[i]))
        {
            int a = string[i];
            int b = string[i + 1];
        }
    }
}
bool f_judge()
{
    if(!f_judge1())//检查回文
    {
        return false;
    }
    else
    {
        bool type = false;
        for(int i = 0; i < len; i++)
        {
            if(string[i] == '?' && string[len - 1 - i] == '?')
            {
                type = true;
            }
            else if(string[i] == '?')
            {
                string[i] = string[len - 1 - i];
            }
        }
        if(type)
        {
            return f_spejudge();
        }
        else
        {
            if(strcmp(string, string1) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
int main(void)
{
    int group = 0;
    scanf("%d", &group);
    while(group--)
    {
        scanf("%d", &len);
        scanf("%s", string);
        scanf("%s", string1);
        if(f_judge())
        {
            printf("Correct.\n");
        }
        else
        {
            printf("Wrong Answer!\n");
        }
    }
}