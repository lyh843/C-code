#include<stdio.h>
#include<math.h>
#define row_size (1024 + 100)
#define col_size (1536 + 100)
int map[row_size][col_size];
int min_x, max_x, min_y, max_y;

void f_paint(int size, int x, int y)
{
    
}

int main(void)
{
    int size = 0;
    int x = 0, y = 0;
    scanf("%d", &size);
    x = min_x = max_x = col_size / 2;
    y = min_y = max_y = row_size / 2;
    f_paint(size, x, y);
}