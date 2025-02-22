#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define N 1000 // size of y
#define M 1000 // size of x
#define O 100 // size of mon
int amount;
int max_y, max_x, min_x = INT_MAX, min_y = INT_MAX;
long long int result;
typedef struct mon
{
    int hp;
    int x;
    int y;
} mon;

mon arr[O];
int mon_x[M][O + 1]; // 第一位是数量，后面是对应的魔物序号 第几行表示对应的x

int edge_left[M][5], edge_right[M][5];

int cmp(const void *a, const void *b)
{
    mon p1 = *(mon *)a;
    mon p2 = *(mon *)b;
    if (p1.x > p2.x)
    {
        return 1;
    }
    else if (p1.x < p2.x)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void f_input()
{
    scanf("%d", &amount);
    for (int i = 1; i <= amount; i++)
    {
        int x = 0, y = 0, hp = 0;
        scanf("%d%d%d", &x, &y, &hp);
        arr[i].x = x;
        arr[i].y = y;
        arr[i].hp = hp;
        if (x > max_x)
        {
            max_x = x;
        }
        if (y > max_y)
        {
            max_y = y;
        }
        if(x < min_x)
        {
            min_x = x;
        }
        if(y < min_y)
        {
            min_y = y;
        }
        mon_x[x][++mon_x[x][0]] = i;
    }
}

void f_edge_left()
{
    //0
    if(min_x == 0)
    {
        int up1 = -1, down1 = INT_MAX, hp1 = 0;
        for (int j = 1; j <= mon_x[0][0]; j++)
        {
            if (arr[mon_x[0][j]].y > up1)
            {
                up1 = arr[mon_x[0][j]].y;
            }
            if (arr[mon_x[0][j]].y < down1)
            {
                down1 = arr[mon_x[0][j]].y;
            }
            if(arr[mon_x[0][j]].hp > hp1)
            {
                hp1 = arr[mon_x[0][j]].hp;
            }
        }
        edge_left[0][0] = up1;
        edge_left[0][1] = down1;
        edge_left[0][2] = 0;
        edge_left[0][3] = 0;
        edge_left[0][4] = hp1;
    }
    else
    {
        edge_left[0][0] = -1;
        edge_left[0][1] = INT_MAX;
        edge_left[0][2] = INT_MAX;
        edge_left[0][3] = -1;
        edge_left[0][4] = 0;
    }

    for (int i = 1; i <= max_x; i++)
    {
        edge_left[i][2] = edge_left[i - 1][2];
        if(mon_x[i][0] == 0)
        {
            edge_left[i][0] = edge_left[i - 1][0];
            edge_left[i][1] = edge_left[i - 1][1];
            edge_left[i][3] = edge_left[i - 1][3];
            edge_left[i][4] = edge_left[i - 1][4];
        }
        else
        {
            edge_left[i][3] = i;
            int up1 = -1, down1 = INT_MAX, hp1 = 0;
            for (int j = 1; j <= mon_x[i][0]; j++)
            {
                if(arr[mon_x[i][j]].y > up1)
                {
                    up1 = arr[mon_x[i][j]].y;
                }
                if (arr[mon_x[i][j]].y < down1)
                {
                    down1 = arr[mon_x[i][j]].y;
                }
                if (arr[mon_x[i][j]].hp > hp1)
                {
                    hp1 = arr[mon_x[i][j]].hp;
                }
            }
            if(up1 > edge_left[i - 1][0])
            {
                edge_left[i][0] = up1;
            }
            else
            {
                edge_left[i][0] = edge_left[i - 1][0];
            }
            if(down1 < edge_left[i - 1][1])
            {
                edge_left[i][1] = down1;
            }
            else
            {
                edge_left[i][1] = edge_left[i - 1][1];
            }
            if (hp1 > edge_left[i - 1][4])
            {
                edge_left[i][4] = hp1;
            }
            else
            {
                edge_left[i][4] = edge_left[i - 1][4];
            }
        }
    }
}

void f_edge_right()
{
    // max
    int up1 = -1, down1 = INT_MAX, hp1 = 0;
    for (int j = 1; j <= mon_x[max_x][0]; j++)
    {
        if (arr[mon_x[max_x][j]].y > up1)
        {
            up1 = arr[mon_x[max_x][j]].y;
        }
        if (arr[mon_x[max_x][j]].y < down1)
        {
            down1 = arr[mon_x[max_x][j]].y;
        }
        if (arr[mon_x[max_x][j]].hp > hp1)
        {
            hp1 = arr[mon_x[max_x][j]].hp;
        }
    }
    edge_right[max_x][0] = up1;
    edge_right[max_x][1] = down1;
    edge_right[max_x][2] = max_x;
    edge_right[max_x][3] = max_x;
    edge_right[max_x][4] = hp1;

    for (int i = max_x - 1; i >= 0; i--)
    {
        edge_right[i][3] = edge_right[i + 1][3];
        if (mon_x[i][0] == 0)
        {
            edge_right[i][0] = edge_right[i + 1][0];
            edge_right[i][1] = edge_right[i + 1][1];
            edge_right[i][2] = edge_right[i + 1][2];
            edge_right[i][4] = edge_right[i + 1][4];
        }
        else
        {
            edge_right[i][2] = i;
            int up1 = -1, down1 = INT_MAX, hp1 = 0;
            for (int j = 1; j <= mon_x[i][0]; j++)
            {
                if (arr[mon_x[i][j]].y > up1)
                {
                    up1 = arr[mon_x[i][j]].y;
                }
                if (arr[mon_x[i][j]].y < down1)
                {
                    down1 = arr[mon_x[i][j]].y;
                }
                if (arr[mon_x[i][j]].hp > hp1)
                {
                    hp1 = arr[mon_x[i][j]].hp;
                }
            }
            if (up1 > edge_right[i + 1][0])
            {
                edge_right[i][0] = up1;
            }
            else
            {
                edge_right[i][0] = edge_right[i + 1][0];
            }
            if (down1 < edge_right[i + 1][1])
            {
                edge_right[i][1] = down1;
            }
            else
            {
                edge_right[i][1] = edge_right[i + 1][1];
            }
            if (hp1 > edge_right[i + 1][4])
            {
                edge_right[i][4] = hp1;
            }
            else
            {
                edge_right[i][4] = edge_right[i + 1][4];
            }
        }
    }
}

void f_result()
{
    int temp_left = 0, temp_right = 0;
    int count = (edge_right[min_x][0] - edge_right[min_x][1] + 1) * (edge_right[min_x][3] - edge_right[min_x][2] + 1) * edge_right[min_x][4];
    for (int i = min_x; i <= max_x; i++)
    {
        if(i == max_x)
        {
            temp_left = (edge_left[max_x][0] - edge_left[max_x][1] + 1) * (edge_left[max_x][3] - edge_left[max_x][2] + 1) * edge_left[max_x][4];
            temp_right = 0;
        }
        else
        {
            temp_left = (edge_left[i][0] - edge_left[i][1] + 1) * (edge_left[i][3] - edge_left[i][2] + 1) * edge_left[i][4];
            temp_right = (edge_right[i + 1][0] - edge_right[i + 1][1] + 1) * (edge_right[i + 1][3] - edge_right[i + 1][2] + 1) * edge_right[i + 1][4];
        }
        if(temp_left + temp_right < count)
        {
            count = temp_left + temp_right;
        }
    }
    printf("%d", count);
}

int main(void)
{
    f_input();
    f_edge_left();
    f_edge_right();
    f_result();
    return 0;
}