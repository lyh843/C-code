#include<stdio.h>

int main(){
    int i, j, *p, *q;
    p = &i;
    q = p;
    *p = 1;
    printf("i = %d, *p = %d, *q = %d\n", i, *p, *q);
    *q = 2;
    printf("i = %d, *p = %d, *q = %d\n", i, *p, *q);
}