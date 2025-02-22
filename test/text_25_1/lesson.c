#include <stdio.h>
#define N 10001 //size of box
#define M 20 //amount son
#define O 10010 //len son
#define P 20 // amount choice
int size, amount_son, amount_choice;
int U[N]; //  1表示还没选
int son[M][O];
int choose[P];//选了后要把son[i][0]变为0

int f_op()
{
    int count = 0;
    int max = 0;
    int choose = 0;
    for (int i = 1; i <= amount_son; i++)
    {
        count = 0;
        for (int j = 1; j <= son[i][0]; j++)
        {
            if(U[son[i][j]] == 1)
            {
                count++;
            }
        }
        if(count > max)
        {
            max = count;
            choose = i;
        }
    }
    return choose;
}

void f_delete(int cho)
{
    for (int i = 1; i <= son[cho][0]; i++)
    {
        U[son[cho][i]] = 0;
    }
}

int main(void) 
{
    scanf("%d%d%d", &size, &amount_son, &amount_choice);
    for (int i = 1; i <= amount_son; i++)
    {
        scanf("%d", &son[i][0]);
        for (int j = 1; j <= son[i][0]; j++)
        {
            scanf("%d", &son[i][j]);
        }
    }
    for (int i = 1; i <= size; i++)
    {
        U[i] = 1;
    }
    int times = amount_choice;
    int num = 0;
    while (times--)
    {
        int cho = f_op();
        f_delete(cho);
        son[cho][0] = 0;
        choose[++num] = cho;
    }
    for (int i = 1; i <= amount_choice; i++)
    {
        printf("%d ", choose[i]);
    }
    return 0;
}