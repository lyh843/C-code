#include<stdio.h>
#include<limits.h>

int main(void)
{
    int group = 0;
    scanf("%d", &group);
    while(group--)
    {
        int amount = 0;
        int max = INT_MIN;
        int number = 0;
        scanf("%d", &amount);
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &number);
            if(number >= max)
            {
                max = number;
            }
        }
        if(max == number)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}