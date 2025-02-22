#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 100 //num_order
#define M 100 //len_order
#define O 100 //len_string

char order[N][M];
int amount_order;
char string[O];
void f_input()
{
    scanf("%d", &amount_order);
    for(int i = 1; i <= amount_order; i++)
    {
        scanf("%s", order[i] + 1);
    }
    scanf("%s", string + 1);
}
void f_op()
{
    bool judge1 = true;//是否有执行
    int len = strlen(string + 1);
    while(judge1)
    {
        judge1 = false;
        for(int i = 1; i <= amount_order && !judge1; i++)
        {
            char *st_1 = strchr(order[i] + 1, '[');
            st_1++;
            char *ed_1 = strchr(st_1, ']');
            char *st_2 = strchr(ed_1, '[');
            st_2++;
            char *ed_2 = strchr(st_2, ']');
            char *op_1 = order[i] + 1;
            char *op_2 = st_2 - 2;
            int len_1 = ed_1 - st_1;
            int len_2 = ed_2 - st_2;
            char *pt1;
            if(*op_1 == '.')
            {
                for(pt1 = string + 1; pt1 <= string + len - len_1 + 1 && !judge1; pt1++)
                {
                    if(strncmp(pt1, st_1, len_1) == 0)
                    {
                        judge1 = true;
                        if(*op_2 == '.')
                        {
                            memmove(pt1 + len_2, pt1 + len_1, (len - (pt1 - string + len_1 - 1)));
                            strncpy(pt1, st_2, len_2);
                            len = len + len_2 - len_1;
                        }
                        else if(*op_2 == '^')
                        {
                            memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                            len -= len_1;
                            memmove(string + 1 + len_2, string + 1, len);
                            strncpy(string + 1, st_2, len_2);
                            len += len_2;
                        }
                        else if(*op_2 == '$')
                        {
                            memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                            len -= len_1;
                            strncpy(string + len + 1, st_2, len_2);
                            len += len_2;
                        }
                    }
                }
            }
            else if(*op_1 == '^')
            {
                pt1 = string + 1;
                if(strncmp(string + 1, st_1, len_1) == 0)
                {
                        judge1 = true;
                        if(*op_2 == '.')
                        {
                            memmove(pt1 + len_2, pt1 + len_1, (len - (pt1 - string + len_1 - 1)));
                            strncpy(pt1, st_2, len_2);
                            len = len + len_2 - len_1;
                        }
                        else if(*op_2 == '^')
                        {
                            memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                            len -= len_1;
                            memmove(string + 1 + len_2, string + 1, len);
                            strncpy(string + 1, st_2, len_2);
                            len += len_2;
                        }
                        else if(*op_2 == '$')
                        {
                            memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                            len -= len_1;
                            strncpy(string + len + 1, st_2, len_2);
                            len += len_2;
                        }
                }
            }
            else if(*op_1 == '$')
            {
                pt1 = string + 1 + len - len_1;
                if(strncmp(pt1, st_1, len_1) == 0)
                {
                    judge1 = true;
                    if(*op_2 == '.')
                    {
                        memmove(pt1 + len_2, pt1 + len_1, (len - (pt1 - string + len_1 - 1)));
                        strncpy(pt1, st_2, len_2);
                        len = len + len_2 - len_1;
                    }
                    else if(*op_2 == '^')
                    {
                        memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                        len -= len_1;
                        memmove(string + 1 + len_2, string + 1, len);
                        strncpy(string + 1, st_2, len_2);
                        len += len_2;
                    }
                    else if(*op_2 == '$')
                    {
                        memmove(pt1, pt1 + len_1, len - (pt1 - string + len_1 - 1));
                        len -= len_1;
                        strncpy(string + len + 1, st_2, len_2);
                        len += len_2;
                    }
                }
            }
        }
    }
    string[len + 1]= 0;
}
int main(void)
{
    f_input();
    f_op();
    printf("%s\n", string + 1);
}