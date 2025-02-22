#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define L 0
#define R 1

typedef struct 
{
    int x, y, hp;
} Monster;

int monster_cmp(const void *a, const void *b)
{
    if(((Monster *)a)->x > ((Monster *)b)->x)
    {
        return 1;
    }
    else if(((Monster *)a)->x == ((Monster *)b)->x)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int amount, left = INT_MAX, right = INT_MIN;
long long result = LLONG_MAX;

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
    qsort(monster, amount, sizeof(Monster), monster_cmp);

    int *max_y[2], *min_y[2], *max_hp[2];
    max_y[L] = (int *)calloc(amount, sizeof(int)), min_y[L] = (int *)calloc(amount, sizeof(int));
    max_hp[L] = (int *)calloc(amount, sizeof(int));

    max_y[L][0] = min_y[L][0] = monster[0].y;
    max_hp[L][0] = monster[0].hp;

    for(int i = 1; i < amount - 1; i ++)
    {
        max_y[L][i] = max(max_y[L][i - 1], monster[i].y);
        min_y[L][i] = min(min_y[L][i - 1], monster[i].y);
        max_hp[L][i] = max(max_hp[L][i - 1], monster[i].hp);
    }

    max_y[R] = (int *)calloc(amount, sizeof(int)), min_y[R] = (int *)calloc(amount, sizeof(int));
    max_hp[R] = (int *)calloc(amount, sizeof(int));

    max_y[R][amount - 1] = min_y[R][amount - 1] = monster[amount - 1].y;
    max_hp[R][amount - 1] = monster[amount - 1].hp;

    for(int i = amount - 2; i >= 0; i--)
    {
        max_y[R][i] = max(max_y[R][i + 1], monster[i].y);
        min_y[R][i] = min(min_y[R][i + 1], monster[i].y);
        max_hp[R][i] = max(max_hp[R][i + 1], monster[i].hp);
    }

    for(int i = 0; i < amount - 1; i++)
    {
        if(monster[i].x == monster[i + 1].x)
        {
            continue;
        }
        long long left_result = (long long)(max_y[L][i] - min_y[L][i] + 1) * (monster[i].x - left + 1) * max_hp[L][i];
        long long right_result = (long long)(max_y[R][i + 1] - min_y[R][i + 1] + 1) * (right - monster[i + 1].x + 1) * max_hp[R][i + 1];
        result = min(result, left_result + right_result);
    }
    
    printf("%lld", result);
    return 0;
}
