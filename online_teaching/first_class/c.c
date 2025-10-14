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
    // 如果result < 100，正常输出
    // 如果result >= 100，并且result < 200它应该输出100
    // 如果result >= 200
    // if - else
    if(result < 100){
        printf("if内部\n");
        printf("height = %d\n", (int)result); //函数调用语句
    }
    else if(result < 200){
        printf("else if内部\n");
        printf("height = 100\n"); //函数调用语句
    }
    else if(result < 300){

    }
    else{
        printf("else内部\n");
    }
    // printf("height = %d\n", (int)result); //函数调用语句
    printf("main函数尾部\n");
}