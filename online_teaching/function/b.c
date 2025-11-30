#include <stdio.h>

void printArray(int arr[], int n);

int main()
{
    int a[5] = {1, 2, 3, 4 ,5};
    printf("%d\n", sizeof(a) / sizeof(int));
    printArray(a, sizeof(a) / sizeof(int));
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf(" ");
}