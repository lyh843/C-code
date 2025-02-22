#include<stdio.h>
#include<string.h>
#define N (100 + 1) //字符串长度
#define M (10 + 1) //规则总数
char string[N];
char rule[M][2][N];
int amount_r, times;
void f_input()
{
    scanf("%s", string + 1);
    scanf("%d%d", &amount_r, &times);
    for(int i = 1; i <= amount_r; i++)
    {
        scanf("%s%s", rule[i][0] + 1, rule[i][1] + 1);
    }
}
void f_op(int num_r)
{
    int len_s = strlen(rule[num_r][0] + 1);
    int len_t = strlen(rule[num_r][1] + 1);
    int len = strlen(string + 1);
    for(int i = 1; i <= len - len_s + 1; i++)
    {
        if(strncmp(string + i, rule[num_r][0] + 1, len_s) == 0)
        {
            memmove(string + i + len_t, string + i + len_s, len + 1 - i - len_s);
            strncpy(string + i, rule[num_r][1] + 1, len_t);
            *(string + len + len_t - len_s + 1) = 0;
        }
    }
}
int main(void)
{
    f_input();
    while(times--)
    {
        for(int i = 1; i <= amount_r; i++)
        {
            f_op(i);
        }
    }
    printf("%s", string + 1);
}