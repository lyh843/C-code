#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 200050
#define M 200

int n, m, b[M];
char s[N], ans[N], out[N];

bool check_par()
{
    for(int i = 1, j = m; i < j; i++, j--)
    {
        if(out[i] != out[j])
        {
            return false;
        }
    }
    return true;
}

bool check()
{
    for(int i = 1; i <= n; i ++)
    {
        if(s[i] == '?' && s[n - i + 1] != '?')
        {
            s[i] = s[n - i + 1];
        }
    }
    m = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] != '?')
        {
            ans[++m] = s[i];
        }
        else
        {
            ans[++m] = '$';
            ans[++m] = '$';
        }
    }
    if(strlen(out + 1) != m)
    {
        return false;
    }
    for(int i = 0; i < 100; i++)
    {
        b[i] = 0;
    }
    char x = 0, y = 0;
    for(int i =  1; i <= m; i++)
    {
        if(ans[i] == '$')
        {
            if(x == 0)
            {
                x = out[i];
            }
            else
            {
                y = out[i];
                if((!isdigit(x)) || (!isdigit(y)))
                {
                    return false;
                }
                if(x == y)
                {
                    int t =(x - '0') * 10 + (y - '0');
                    if(b[t] == 2)
                    {
                        return false;
                    }
                    b[t]++;
                    x = y = 0;
                    continue;
                }
                int t1 = (x - '0') * 10 + (y - '0');
                int t2 = (y - '0') * 10 + (x - '0');
                if(b[t1] == 2 && b[t2] == 2)
                {
                    return false;
                }
                if(b[t1] < 2)
                {
                    b[t1]++;
                }
                else
                {
                    b[t2]++;
                }
                x = y = 0;
            }
        }
        else
        {
            if(ans[i] != out[i])
            {
                return false;
            }
        }
    }
    if(!check_par())
    {
        return false;
    }
    return true;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", out + 1);
        puts(check() ? "Correct." : "Wrong Answer!");
    }
    return 0;
}