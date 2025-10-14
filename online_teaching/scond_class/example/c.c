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
}