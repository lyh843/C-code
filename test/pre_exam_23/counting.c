#include<stdio.h>
#include<stdbool.h>
#define N 200
int size_row, size_col;
char map[N][N];
int count;
void f_input()
{
    scanf("%d%d", &size_row, &size_col);
    for(int i = 1; i <= size_row; i++)
    {
        scanf("%s", map[i] + 1);
    }
}
void f_count()
{
    for(int size = 1; size <= size_row && size <= size_col; size++)//size of the square
    {
        for(int loc_row = 1; loc_row <= size_row; loc_row++)
        {
            for(int loc_col = 1; loc_col <= size_col; loc_col++)
            {
                bool judge = true;
                if(map[loc_row][loc_col] == '/' && map[loc_row][loc_col + 1] == '\\')
                {
                    for(int i = 1; i <= size && judge; i++)
                    {
                        if(map[loc_row - 1 + i][loc_col + 1 - i] != '/' || map[loc_row - 1 + i][loc_col + i] != '\\')
                        {
                            judge = false;
                        }
                    }
                    for(int i = 1; i <= size && judge; i++)
                    {
                        if(map[loc_row + size - 1 + i][loc_col - size + i] != '\\' || map[loc_row + size - 1 + i][loc_col + 1 + size - i] != '/')
                        {
                            judge = false;
                        }
                    }
                    if(judge)
                    {
                        count++;
                    }
                }
            }
        }
    }
}
int main(void)
{
    f_input();
    f_count();
    printf("%d\n", count);
}