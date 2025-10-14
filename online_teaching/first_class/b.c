#include<stdio.h>

int main(){
    int i;
    float f;
    scanf("%d%f", &i, &f);
    // scanf("%f", &f);
    // %d 整数 12
    // %f 浮点数
    // %c 字符 'a' 'b' '1'
    // %s 字符串 "ab" "12"
    printf("%d\n%5.2f\n", i, f);
    printf("%d\n%6.2f\n", i, f);
    printf("%d\n%7.2f\n", i, f);
    printf("%d\n%8.2f\n", i, f);
    printf("%d\n%9.2f\n", i, f);
    // printf("%f", f);
    // %m.nf
    // m 预留多大的位置给这个数字
    // n 表示保留几位小数
    // \n 回车、换行
}