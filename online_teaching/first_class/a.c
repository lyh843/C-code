#include<stdio.h>
#define g 10
// #define 变量名 数值

float height(float times){
    return 0.5 * g * times * times;
}
int main(void){
    float result; // 变量的声明
    float times;
    scanf("%f", &times);
    result = height(times); // 赋值语句
    printf("height = %d\n", (int)result); //函数调用语句
}