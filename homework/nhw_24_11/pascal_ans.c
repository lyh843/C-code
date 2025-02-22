#include <stdio.h>
int a, b;
long long C[36][36];
long long solve(int a, int b) 
{
    if (C[a][b] != 0) 
    {
        return C[a][b];
    }
    if (b == 0 || b == a) 
    {
        C[a][b] = 1;
        return C[a][b];
    }
    return C[a][b] = solve(a - 1, b - 1) + solve(a - 1, b);
}
int main() 
{
    for(int i = 0; i <= 36; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            C[i][j] = solve(i, j);
        }
    }
    scanf("%d%d", &a, &b);
    printf("%lld", C[a - 1][b - 1]);
    return 0;
}