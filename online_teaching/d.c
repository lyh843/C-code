#include<stdio.h>
#define g 10
// #define 变量名 数值

float height(int times){
    return 0.5 * g * times * times;
}
// 输出times为 1-10 时的result值
int main(void){
    float result; // 变量的声明
    int times;
    // scanf("%d", &times);
    for(times = 1; times <= 10; times = times + 3){
        result = height(times); // 赋值语句
        printf("times = %d, height = %d\n", times, (int)result); //函数调用语句
    }
    printf("times = %d", times);
    //for(初始化； 条件； 每次循环的操作) 
    // 步长 每次循环走一步，步长为多少
}