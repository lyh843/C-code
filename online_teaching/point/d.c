#include<stdio.h>

int main(){
    int arr[3] = {1,2,3};
    int *p = arr;     // 等价于 &arr[0]

    printf("%d\n", *(p+1));
}

a b c
10 11 12
12 + 6 = 16 % 16 = 0