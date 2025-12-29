#include<stdio.h>
struct A {
    char c; // 1个字节
    char d;
    int  i; // 4个字节

};
int main(){
    printf("%d", sizeof(struct A));
}