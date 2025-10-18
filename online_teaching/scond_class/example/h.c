#include<stdio.h>

int main(){
    int a = 1;
    printf("%d\n", a++);
    // printf a = 1
    // a++    a = 2
    printf("%d\n", ++a);
    // ++a    a = 3
    // printf a = 3
    printf("%d\n", a);
    // printf a = 3
}