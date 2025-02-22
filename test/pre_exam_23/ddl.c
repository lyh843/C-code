#include<stdio.h>
#define N 100
int num_task = 0, time[2][N];//0 需要的时间  1 剩下的时间
void bubblesort()
{
    int temp0 = 0;
    int temp1 = 0;
    for(int i = 1; i <= num_task; i++)
    {
        for(int j = 1; j <= num_task - i; j++)
        {
            if(time[1][j] <= time[1][j + 1])
            {
                temp0 = time[0][j + 1];
                time[0][j + 1] = time[0][j];
                time[0][j] = temp0;
                temp1 = time[1][j + 1];
                time[1][j + 1] = time[1][j];
                time[1][j] = temp1;
            }
        }
    }
} 
void search()
{
    int max_time = time[1][1];
    for(int i = 1; i <= num_task; i++)
    {
        if(max_time >= time[1][i])
        {
            max_time = time[1][i];
        }
        max_time -= time[0][i];
        if(max_time < 0)
        {
            printf("-1\n");
            return;
        }
    }
    printf("%d", max_time);
}

int main(void)
{
    scanf("%d", &num_task);
    for(int i = 1; i <= num_task; i++)
    {
        scanf("%d%d", &time[0][i], &time[1][i]);
    }
    bubblesort();
    search();
    return 0;
}