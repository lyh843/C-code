#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) > (b) ? (b) : (a))

typedef struct
{
    int x, y, hp;
}Monster;

int amount, left = INT_MAX, right = INT_MIN;
int result = INT_MAX;
int main(void)
{
    scanf("%d", &amount);
    Monster *monster = (Monster *)malloc(amount * sizeof(Monster));
    for(int i = 0; i < amount; i++)
    {
        int x, y, hp;
        scanf("%d%d%d", &x, &y, &hp);
        monster[i] = (Monster){x, y, hp};
        left = min(left, x);
        right = max(right, x);
    }

    for(int loc_x = left; loc_x < right; loc_x++)
    {
        int max_x[2] = {0, 0},
            max_y[2] = {0, 0},
            min_x[2] = {INT_MAX, INT_MAX},
            min_y[2] = {INT_MAX, INT_MAX},
            max_hp[2] = {0, 0};
        for(int i = 0; i < amount; i++)
        {
            if(monster[i].x <= loc_x)
            {
                max_x[0] = max(max_x[0], monster[i].x);
                min_x[0] = min(min_x[0], monster[i].x);
                max_y[0] = max(max_y[0], monster[i].y);
                min_y[0] = min(min_y[0], monster[i].y);
                max_hp[0] = max(max_hp[0], monster[i].hp);
            }
            else
            {
                max_x[1] = max(max_x[1], monster[i].x);
                min_x[1] = min(min_x[1], monster[i].x);
                max_y[1] = max(max_y[1], monster[i].y);
                min_y[1] = min(min_y[1], monster[i].y);
                max_hp[1] = max(max_hp[1], monster[i].hp);
            }
        }
        result = min(result, 
                    (max_y[0] - min_y[0] + 1) * (max_x[0] - min_x[0] + 1) * max_hp[0] + 
                    (max_y[1] - min_y[1] + 1) * (max_x[1] - min_x[1] + 1) * max_hp[1]);
    }

    

    printf("%d", result);
    return 0;
}