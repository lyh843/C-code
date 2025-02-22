#include<stdio.h>
#include<stdbool.h>
#define N 51
int map[N][N], num_row, num_col;
int wro_map[N][N];

void f_wrmap()
{
    for(int i = 1; i <= num_row; i++)
    {
        for(int j = 1; j <= num_col; j++)
        {
            if(map[i][j] == -1 && j == 1)
            {
                wro_map[i][j] = -1;
            }
            else if(map[i][j] == 1 && j == num_col)
            {
                wro_map[i][j] = -1;
            }
            else if(map[i][j] == 1 && map[i][j + 1] == -1)
            {
                wro_map[i][j] = -1;
                wro_map[i][j + 1] = -1;
            }
        }
    }
}

void f_move(int loc_col)
{
    int loc_row = 1;
    int temp_row[2] = {0};
    int pre_loc[2] = {0};
    bool judge = true;
    while(loc_row != num_row + 1 && judge)
    {
        if(wro_map[loc_row][loc_col] == -1)
        {
            judge = false;
        }
        else
        {
            loc_col += map[loc_row][loc_col];
            loc_row++;
        }
        if(wro_map[loc_row][loc_col] == -1)
        {
            judge = false;
        }
    }
    if(judge)
    {
        printf("%d ", loc_col - 1);
    }
    else
    {
        printf("-1 ");
    }
}

int main(void)
{
    scanf("%d%d", &num_row, &num_col);
    for(int i = 1; i <= num_row; i++)
    {
        for(int j = 1; j <= num_col; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    f_wrmap();
    for(int i = 1; i <= num_col; i++)
    {
        f_move(i);
    }
    printf("\n");
}