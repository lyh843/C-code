#include<stdio.h>

void f1(float a, int *b, float* c){
    *b = (int)a;
    *c = a - *b;
}
int main(){
    float a = 3.14;
    int b;
    float c;
    f1(a, &b, &c);
    printf("%d %.2f", b, c);
}