#include<stdio.h>

int main(void){
    char a = 'a'; // 初始化
    char b[13] = "hello, world";    // 空格占了一个字符的位置，因此这个字符串有12格
    printf("%c\n", a);
    printf("%s\n", b);
    return 0;
}