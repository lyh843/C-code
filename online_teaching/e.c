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
    times = 1; // 初始化
    while(times <= 10){ // 循环执行的条件
        result = height(times); // 赋值语句
        printf("times = %d, height = %d\n", times, (int)result); //函数调用语句
        times = times + 1; // 每次循环对times的操作
    }
    printf("times = %d", times);
}