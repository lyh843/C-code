#include<stdio.h>
#include<math.h>
#define Limit 0.0001 //精度
#define N 100
int n = 0, p = 0;
int arr[N];//系数
double left, right;

double f_function(double x)
{
    double result_rule = 0;
    for(int i = 0; i <= n; i++)
    {
        result_rule += arr[i] * pow(x, i);
    }
    return pow(result_rule, p);
}

double f_rule(double l, double r)
{
    double result_rule = (4 * f_function((l + r) / 2) + f_function(l) + f_function(r)) * (r - l) / 6;
    return result_rule;
}

double f_op(double l, double r, double limit)
{
    double mid = (l + r) / 2;
    double result1 = f_rule(l, r);
    double result2 = f_rule(l, mid);
    double result3 = f_rule(mid, r);
    if(fabs(result3 + result2 - result1) <= 15 * limit)
    {
        return result2 + result3 + (result2 + result3 - result1) / 15;
    }
    else
    {
        return f_op(l, mid, limit / 2) + f_op(mid, r, limit / 2);
    }
}

int main(void)
{
    scanf("%d%d", &n, &p);
    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%lf%lf", &left, &right);
    double result = f_op(left, right, Limit);
    printf("%lf", result);
}