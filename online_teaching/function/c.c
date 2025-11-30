#include <stdio.h>

int arr[5] = {1, 2, 3, 4, 5};

void setZero(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int main(){
    int arr[3] = {1, 2, 3};
    setZero(arr, 3);	// 传入只需要传名称
    for(int i = 0; i < 3; i++){
        for(int i = 0; i < 3; i++){
            
        }
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < 3; i++){

    }
}