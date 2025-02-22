#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 600 //地图大小
#define M 100000000 //最大值的数目
#define O 60 //初始坐标
int size_row, size_col, size_hit;
int arr[N + 2 * O][N + 2 * O];//从开始打
int max, count;
int loc_row, loc_col, end_row, end_col;
bool down, left, right;
int num_max, arr_max[2][M];
FILE* file;
void f_input()
{
    scanf("%d%d%d", &size_row, &size_col, &size_hit);
    for(int i = 0; i < size_row; i++)
    {
        for(int j = 0; j < size_col; j++)
        {
            scanf("%d", &arr[O + i][O + j]);
        }
    }
}
void f_end()
{
    if(size_row % 2 == 0)
    {
        end_col = O;
    }
    else
    {
        end_col = O + size_col - 1;
    }
    end_row = size_row + O - 1;
}
int f_firhit()
{
    int temp_count = 0;
    for(int i = -size_hit; i <= size_hit; i++)
    {
        for(int j = -size_hit + abs(i); j <= size_hit - abs(i); j++)
        {
            temp_count += arr[O + i][O + j];
        }
    }
    return temp_count;
}
void f_move()
{
    down = false;
    right = false;
    left = false;
    if(loc_row % 2 == 0)//往右走
    {
        if(loc_col != size_col + O - 1)
        {
            right = true;
            loc_col += 1;
        }
        else
        {
            down = true;
            loc_row += 1;
        }
    }
    else
    {
        if(loc_col != O)
        {
            left = true;
            loc_col -= 1;
        }
        else
        {
            down = true;
            loc_row += 1;
        }
    }
}
void f_hit()
{
    if(down)
    {
        for(int j = -size_hit; j <= size_hit; j++)
        {
            count -= arr[loc_row + abs(j) - size_hit - 1][loc_col + j];
            count += arr[loc_row - abs(j) + size_hit][loc_col + j];
        }
    }
    else if(left)
    {
        for(int i = -size_hit; i <= size_hit; i++)
        {
            count -= arr[loc_row + i][loc_col - abs(i) + 1 + size_hit];
            count += arr[loc_row + i][loc_col + abs(i) - size_hit];
        }
    }
    else
    {
        for(int i = - size_hit; i <= size_hit; i++)
        {
            count -= arr[loc_row + i][loc_col - 1 - size_hit + abs(i)];
            count += arr[loc_row + i][loc_col + size_hit - abs(i)];
        }
    }
}
void f_op()
{
    loc_row = O, loc_col = O;
    max = f_firhit();
    count = max;
    num_max = 1;
    arr[0][num_max] = 1;
    arr[1][num_max] = 1;
    while(loc_row != end_row || loc_col != end_col)
    {
        f_move();
        f_hit();
        if(count > max)
        {
            max = count;
            num_max = 1;
            arr[0][num_max] = loc_row - O + 1;
            arr[1][num_max] = loc_col - O + 1;
        }
        else if(count == max)
        {
            num_max++;
            arr[0][num_max] = loc_row - O + 1;
            arr[1][num_max] = loc_col - O + 1;
        }
    }
}
void f_print()
{
    fprintf(file, "%d %d\n", max, num_max);
    for(int i = 1; i <= num_max; i++)
    {
        fprintf(file, "%d %d\n", arr[0][i], arr[1][i]);
    }
}
int main(void)
{
    freopen("D:\\yh\\university\\class\\C\\code\\pre_exam_22\\whac-a-mole6.in", "r", stdin);
    file = fopen("res.out", "w");
    f_input();
    f_end();
    f_op();
    f_print();
    return 0;
}