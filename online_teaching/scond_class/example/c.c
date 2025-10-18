#include<stdio.h>

int main(){
    int a = 12345, b = 67890;
    scanf("%d/%d", &a, &b);
    printf("%d/%d\n", a, b);
    a = 67890;
    b = 12345;
    scanf("%d / %d", &a, &b);
    printf("%d / %d\n", a, b);
    
    scanf("/ %d", &b);
    printf("%d / %d\n", a, b);

    // int i, j;
    // scanf("%d%d", &i, &j);
    // printf("%d %d\n", i, j);
    // scanf("%d %d", &i, &j);
    // printf("%d %d\n", i, j);
}