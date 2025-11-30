#include <stdio.h>
#include "math.h"
// #include "math.c"

int main(){
    int a, b = 0;
    scanf("%d%d", &a, &b);
    printf("a + b = %d\na - b = %d", add(a, b), sub(a, b));
}
