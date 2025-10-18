#include<stdio.h>

int main(){
    int a = 1;
    float b = 2.1;
    float c = a / b;
    a = a / b; // 对a有副作用
    float b2 = 1.4;    
    int a2 = (int)b2; // 对b2无副作用
    a += 2;
    a = a + 2;
    printf("%d", a);


    int i = 1, j = 2;
    float k = 1.5;
    printf("%d\n", i < j);
    printf("%d", i < j < k);

    int a3 = 1, b3 = 0;
    printf("%d %d", !a3, !b3);
}