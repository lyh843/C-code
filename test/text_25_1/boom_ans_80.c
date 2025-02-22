#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX_N (100000 + 5)
#define L 0
#define R 1

typedef struct
{
    int x, y, hp;
}Monster;

int amount, left = INT_MAX, right = INT_MIN;
long long int result = LLONG_MAX;
int max_x[2][MAX_N], max_y[2][MAX_N], min_x[2][MAX_N], min_y[2][MAX_N], max_hp[2][MAX_N];

int main(void)
{
    scanf("%d", &amount);
    Monster *monster = (Monster *)malloc(amount * sizeof(Monster));

    for(int i = 0; i < MAX_N; i++)
    {
        min_x[L][i] = min_x[R][i] = INT_MAX;
        min_y[L][i] = min_y[R][i] = INT_MAX;
    }

    for(int i = 0; i < amount; i++)
    {
        int x, y, hp;
        scanf("%d%d%d", &x, &y, &hp);
        monster[i] = (Monster){x, y, hp};
        left = min(left, x);
        right = max(right, x);
        max_x[L][x] = max_x[R][x] = x;
        min_x[L][x] = min_x[R][x] = x;
        max_y[L][x] = max_y[R][x] = max(max_y[L][x], y);
        min_y[L][x] = min_y[R][x] = min(min_y[L][x], y);
        max_hp[L][x] = max_hp[R][x] = max(max_hp[L][x], hp);
    }

    for(int loc_x = left + 1; loc_x <= right; loc_x++)
    {
        max_x[L][loc_x] = max(max_x[L][loc_x - 1], max_x[L][loc_x]);
        min_x[L][loc_x] = min(min_x[L][loc_x - 1], min_x[L][loc_x]);
        max_y[L][loc_x] = max(max_y[L][loc_x - 1], max_y[L][loc_x]);
        min_y[L][loc_x] = min(min_y[L][loc_x - 1], min_y[L][loc_x]);
        max_hp[L][loc_x] = max(max_hp[L][loc_x - 1], max_hp[L][loc_x]);
    }

    for(int loc_x = right - 1; loc_x >= left; loc_x--)
    {
        max_x[R][loc_x] = max(max_x[R][loc_x + 1], max_x[R][loc_x]);
        min_x[R][loc_x] = min(min_x[R][loc_x + 1], min_x[R][loc_x]);
        max_y[R][loc_x] = max(max_y[R][loc_x + 1], max_y[R][loc_x]);
        min_y[R][loc_x] = min(min_y[R][loc_x + 1], min_y[R][loc_x]);
        max_hp[R][loc_x] = max(max_hp[R][loc_x + 1], max_hp[R][loc_x]);
    }

    for(int loc_x = left; loc_x < right; loc_x++)
    {
        long long left_result = (long long)(max_y[L][loc_x] - min_y[L][loc_x] + 1) * (max_x[L][loc_x] - min_x[L][loc_x] + 1) * max_hp[L][loc_x];
        long long right_result = (long long)(max_y[R][loc_x + 1] - min_y[R][loc_x + 1] + 1) * (max_x[R][loc_x + 1] - min_x[R][loc_x + 1] + 1) * max_hp[R][loc_x + 1];
        result = min(result, (left_result + right_result));
    }

    printf("%lld", result);
    return 0;
}