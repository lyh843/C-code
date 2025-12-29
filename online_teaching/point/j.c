#include<stdio.h>
int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

void print(int (*fp)(int, int), int a, int b){
    printf("%d\n", fp(a, b));
}

int main(){
    int a = 10;
    int b = 5;
    print(add, a, b);
    print(sub, a, b);

    const int c = 5;

    int *p3 = &a;
    p3 = &b;
}