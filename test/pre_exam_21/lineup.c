#include<stdio.h>
#define N 100//size_row
#define M 100//size_col
#define O 10 //num_pos
int size_row = 0, size_col = 0;
int x[9] = {0}, y[9] = {0};

typedef struct line
{
    int num;
    struct line* right;
    struct line* down;
}line;
line arr[N][M];
line *current[O];
void f_print_arr();
void f_begin()
{
    for(int i = 0; i <= size_row + 1; i++)
    {
        for(int j = 0; j <= size_col + 1; j++)
        {
            arr[i][j].num = i *size_col + j;
            if(i != size_row + 1)
            {
                arr[i][j].down = &arr[i + 1][j];
            }
            else
            {
                arr[i][j].down = NULL;
            }
            if(j != size_col + 1)
            {
                arr[i][j].right = &arr[i][j + 1];
            }
            else
            {
                arr[i][j].right = NULL;
            }
        }
    }
}

void f_move(int x, int y, int num)
{
    current[num] = &arr[0][0];
    for(int i = 0; i < x; i++)
    {
        current[num] = current[num]->down;
    }
    for(int i = 0; i < y; i++)
    {
        current[num] = current[num]->right;
    }
}

void f_opearate()
{
    //操作
    f_move(x[1] - 1, y[1], 1);//矩阵1左上方元素的上方
    f_move(x[3] - 1, y[3], 2);//矩阵2左上方元素的上方
    f_move(x[1], y[2], 3);//矩阵1右上方元素
    f_move(x[3], y[4], 4);//矩阵2右上方元素
    f_move(x[1], y[1] - 1, 5);//矩阵1左上方元素的左侧
    f_move(x[3], y[3] - 1, 6);//矩阵2左上方元素的左侧
    f_move(x[2], y[1], 7);//矩阵1左下方元素
    f_move(x[4], y[3], 8);//矩阵2左下方元素

    for(int i = 0; i <= y[2] - y[1]; i++)//上边
    {
        if(i != 0)
        {
            current[1] = current[1]->right;
            current[2] = current[2]->right;
        }
        current[9] = current[1]->down;
        current[1]->down = current[2]->down;
        current[2]->down = current[9];
    }//光标停在了矩阵1的右上元素的上方，矩阵二右上元素的上方
    for(int j = 0; j <= x[2] - x[1]; j++)//右边
    {
        if(j != 0)
        {
            current[4] = current[4]->down;
            current[3] = current[3]->down;
        }
        current[9] = current[3]->right;
        current[3]->right = current[4]->right;
        current[4]->right = current[9];
    }//光标停在了矩阵1的右下方元素，矩阵二的右下方元素
    for(int j = 0; j <= x[2] - x[1]; j++)//左边
    {
        if(j != 0)
        {
            current[6] = current[6]->down;
            current[5] = current[5]->down;
        }
        current[9] = current[5]->right;
        current[5]->right = current[6]->right;
        current[6]->right = current[9];
    }
    for(int i = 0; i <= y[2] - y[1]; i++)
    {
        if(i != 0)
        {
        current[7] = current[7]->right;
        current[8] = current[8]->right;
        }
        current[9] = current[7]->down;
        current[7]->down = current[8]->down;
        current[8]->down = current[9];
    }//光标停在了矩阵1的右上元素的上方，矩阵二右上元素的上方
}
void f_print()
{
    int number = 0;
    long long result = 0;
    scanf("%d", &number);
    f_move(number, 1, 1);
    for(int i = 0; i < size_col; i++)
    {
        result += current[1]->num;
        if(current[1] != NULL)
        {
            current[1] = current[1]->right;
        }
    }
    printf("%lld\n", result);
}
int main(void)
{
    scanf("%d%d", &size_row, &size_col);
    int num_op = 0;
    scanf("%d", &num_op);
    f_begin();
    while(num_op--)
    {
        for(int i = 1; i <= 4; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        f_opearate();
        f_print();
    }
    return 0;
}