#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
    int row = 0;
    printf("Please enter the size of row:");
    scanf("%d", &row);
    for(int i = 1; i <= row / 2; i++)
    {
        printf("R%d = %d\n", i, (int)((2 * row * sin(i * 3.1416 / row)) + 0.5));
    }
    if(row % 2 == 1)
    {
        printf("R%d = %d\n", row / 2 + 1, 2 * row);
        for(int i = row / 2 + 1; i < row; i++)
        {
            printf("R%d = %d\n", i + 1, (int)((2 * row * sin(i * 3.1416 / row)) + 0.5));
        }
    }
    else
    {
        for(int i = row / 2; i < row; i++)
        {
            printf("R%d = %d\n", i + 1, (int)((2 * row * sin(i * 3.1416 / row)) + 0.5));
        }
    }
    system("pause");
    return 0;
}