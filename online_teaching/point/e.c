#include<stdio.h>


void print(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int *p = arr;
    for(int i = 0; i < 5; i++){
        printf("%d ", *p);
        p++;
    }
    printf("\n");
    int *q = arr;
    for(int i = 0; i < 5; i++){
        printf("%d ", *(q + i));
    }
    printf("\n");

    int *r = arr;
    for(int i = 0; i < 5; i++){
        printf("%d ", r[i]);
    }
    printf("\n");

    print(arr, 5);
}