#include<stdio.h>
#include<stdbool.h>
#define N 50 //the size of the map
char string[N][N] = {0};//第六行，第六列开始摆
int alive_white = 0;
int alive_black_1 = 0, alive_black_2 = 0;
void f_count_white(int loc_row, int loc_col)
{
    int count_right = 0, count_down = 0, count_rightdown = 0, count_leftdown = 0;
    int right_blank = 0, down_blank = 0, rightdown_blank = 0, leftdown_blank = 0;
    int loc_rb = 0, loc_db = 0, loc_rdb = 0, loc_ldb = 0;
    for(int i = 1; i <= 4; i++)//右边
    {
        if(string[loc_row][loc_col + i] == '*')
        {
            count_right++;
        }
        else if(string[loc_row][loc_col + i] == '_')
        {
            right_blank++;
        }
        else if(string[loc_row][loc_col + i] == '#')
        {
            loc_rb = i;
        }
    }
    if(string[loc_row][loc_col - 1] == '_')
    {
        right_blank++;
    }

    for(int i = 1; i <= 4; i++)//下边
    {
        if(string[loc_row + i][loc_col] == '*')
        {
            count_down++;
        }
        else if(string[loc_row + i][loc_col] == '_')
        {
            down_blank = 1;
        }
        else if(string[loc_row + i][loc_col] == '#')
        {
            loc_db = i;
        }
    }
    if(string[loc_row - 1][loc_col] == '_')
    {
        down_blank++;
    }

    for(int i = 1; i <= 4; i++)//右下边
    {
        if(string[loc_row + i][loc_col + i] == '*')
        {
            count_rightdown++;
        }
        else if(string[loc_row + i][loc_col + i] == '_')
        {
            rightdown_blank = 1;
        }
        else if(string[loc_row + i][loc_col + i] == '#')
        {
            loc_rdb = i;
        }
    }
    if(string[loc_row - 1][loc_col - 1] == '_')
    {
        rightdown_blank++;
    }

    for(int i = 1; i <= 4; i++)//左下边
    {
        if(string[loc_row + i][loc_col - i] == '*')
        {
            count_leftdown++;
        }
        else if(string[loc_row + i][loc_col - i] == '_')
        {
            leftdown_blank = 1;
        }
        else if(string[loc_row + i][loc_col - i] == '#')
        {
            loc_ldb = i;
        }
    }
    if(string[loc_row - 1][loc_col + 1] == '_')
    {
        leftdown_blank++;
    }

    if(count_right == 3 && right_blank && (loc_rb == 0 || loc_rb == 4))
    {   
        alive_white = 1;
    }
    if(count_down == 3 && down_blank && (loc_db == 0 || loc_db == 4))
    {
        alive_white = 1;
    }
    if(count_rightdown == 3 && rightdown_blank && (loc_rdb == 0 || loc_rdb == 4) )
    {
        alive_white = 1; 
    }
    if(count_leftdown == 3 && leftdown_blank && (loc_ldb == 0 || loc_ldb == 4) )
    {
        alive_white = 1; 
    }
}

void f_count_black(int loc_row, int loc_col)
{
    int count_right = 0, count_down = 0, count_rightdown = 0, count_leftdown = 0;
    int right_blank = 0, down_blank = 0, rightdown_blank = 0, leftdown_blank = 0;
    int loc_rw = 0, loc_dw = 0, loc_rdw = 0, loc_ldw = 0;
    int loc1 = 0, loc2 = 0, loc3 = 0, loc4 = 0;
    for(int i = 1; i <= 4; i++)//右边
    {
        if(string[loc_row][loc_col + i] == '#')
        {
            count_right++;
        }
        else if(string[loc_row][loc_col + i] == '_')
        {
            right_blank = 1;
            loc1 = i;
        }
        else if(string[loc_row][loc_col + i] == '*')
        {
            loc_rw = i;
        }
    }
    if(string[loc_row][loc_col - 1] == '_')
    {
        right_blank++;
    }

    for(int i = 1; i <= 4; i++)//下边
    {
        if(string[loc_row + i][loc_col] == '#')
        {
            count_down++;
        }
        else if(string[loc_row + i][loc_col] == '_')
        {
            down_blank = 1;
            loc2 = i;
        }
        else if(string[loc_row + i][loc_col] == '*')
        {
            loc_dw = i;
        }
    }
    if(string[loc_row - 1][loc_col] == '_')
    {
        down_blank++;
    }

    for(int i = 1; i <= 4; i++)//右下边
    {
        if(string[loc_row + i][loc_col + i] == '#')
        {
            count_rightdown++;
        }
        else if(string[loc_row + i][loc_col + i] == '_')
        {
            rightdown_blank = 1;
            loc3 = i;
        }
        else if(string[loc_row + i][loc_col + i] == '*')
        {
            loc_rdw = i;
        }
    }
    if(string[loc_row - 1][loc_col - 1] == '_')
    {
        rightdown_blank++;
    }

    for(int i = 1; i <= 4; i++)//右下边
    {
        if(string[loc_row + i][loc_col - i] == '#')
        {
            count_leftdown++;
        }
        else if(string[loc_row + i][loc_col - i] == '_')
        {
            leftdown_blank = 1;
            loc4 = i;
        }
        else if(string[loc_row + i][loc_col - i] == '*')
        {
            loc_ldw = i;
        }
    }
    if(string[loc_row - 1][loc_col + 1] == '_')
    {
        leftdown_blank++;
    }

    if(count_right == 3 && right_blank && (loc_rw == 0 || loc_rw == 4))
    {
        if(right_blank == 2 && loc1 == 4)
        {
            alive_black_2++;
        }
        else if(right_blank >= 1)
        {
            alive_black_1++;
        }
    }
    if(count_down == 3 && down_blank && (loc_dw == 0 || loc_dw == 4))
    {
        if(down_blank == 2 && loc2 == 4)
        {
            alive_black_2++;
        }
        else if(down_blank >= 1)
        {
            alive_black_1++;
        }
    }
    if(count_rightdown == 3 && rightdown_blank && (loc_rdw == 0 || loc_rdw == 4))
    {
        if(rightdown_blank == 2 && loc3 == 4)
        {
            alive_black_2++;
        }
        else if(rightdown_blank >= 1)
        {
            alive_black_1++;
        }
    }
    if(count_leftdown == 3 && leftdown_blank && (loc_ldw == 0 || loc_ldw == 4))
    {
        if(leftdown_blank == 2 && loc4 == 4)
        {
            alive_black_2++;
        }
        else if(leftdown_blank >= 1)
        {
            alive_black_1++;
        }
    }
}
void f_judge()//只能往右下方走
{
    for(int i = 6; i <= 25; i++)
    {
        for(int j = 6; j <= 25; j++)
        {
            if(string[i][j] == '#')
            {
                f_count_black(i, j);
            }
            else if(string[i][j] == '*')
            {
                f_count_white(i, j);
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
        alive_white = 0;
        alive_black_1 = 0;
        alive_black_2 = 0;
        for(int i = 6; i <= 25; i++)
        {
            scanf("%s", *(string + i) + 6);
        }
        f_judge();
        if(alive_white >= 1)//白子有四连
        {
            printf("Lose\n");
        }
        else if(alive_black_2 >= 1)//黑子有一个四连两边空
        {   
            printf("Win\n");
        }
        else if(alive_black_1 >= 2)//黑子有两个四连，各有一边空位
        {
            printf("Win\n");
        }
        else
        {
            printf("Not Sure\n");
        }
    }
}