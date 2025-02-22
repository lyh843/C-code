#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100 //len of string
#define M 100 //num of str
char string[N];
char delim;
char *str[M];
int num;
void strsplit()
{
    num = 0;
    str[0] = strtok(string, &delim);
    num++;
    while(1)
    {
        str[num] = strtok(NULL, &delim);
        if(str[num] == NULL)
        {
            break;
        }
        else
        {
            num++;
        }
    }
}
int strcmp1(const void *str1, const void *str2)
{
    char *a = *(char **)str1;
    char *b = *(char **)str2;
    return strcmp(a, b);
}

int main(void)
{
    scanf("%s", string);
    getchar();
    delim = getchar();
    strsplit();
    qsort(str, num, sizeof(char *), strcmp1);
    for(int i = 0; i < num; i++)
    {
        printf("%s\n", str[i]);
    }
}