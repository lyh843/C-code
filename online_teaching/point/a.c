#include<stdio.h>

int main(){
    int i = 1;
    int *p = &i;
    printf("%d %d\n", i, *p);
    i++;
    printf("%d %d\n", i, *p);
    (*p)++;
    printf("%d %d\n", i, *p);
}

// int main(){
//     int a = 1;
//     int b = a;
//         printf("%d %d\n", a, b);
//     a++;
//     printf("%d %d\n", a, b);
//     b++;
//     printf("%d %d\n", a, b);
// }