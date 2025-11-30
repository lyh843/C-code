int n = 2;

void printArray(int arr[], int n)
{
    if (n == 0)
        return;
    printArray(arr, n - 1); // step 1
    printf("%d ", arr[n - 1]);  // step8    arr[1]
}


void printArray(int arr[], int n - 1)   // step 2
{
    if (n == 0) // step 3
        return;
    printArray(arr, n - 2);     // step 4
    printf("%d ", arr[n - 1 - 1]);  // step7 arr[0]
}

void printArray(int arr[], int n - 2)   // step 5
{
    if (n == 0) // step 6 
        return;
    printArray(arr, n - 3);
    printf("%d ", arr[n - 2 - 1]);
}