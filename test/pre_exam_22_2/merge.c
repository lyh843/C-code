#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define N 1000
int arr1[N], arr2[N], arr3[2 * N];
int loc_max1 = 0, loc_max2 = 0;
int num1, num2;
int main(void)
{
    scanf("%d", &num1);
    for(int i = 0; i < num1; i++)
    {
        scanf("%d", &arr1[i]);
        if(arr1[i] > arr1[loc_max1])
        {
            loc_max1 = i;
        }
    }
    scanf("%d", &num2);
    for(int i = 0; i < num2; i++)
    {
        scanf("%d", &arr2[i]);
        if(arr2[i] > arr2[loc_max2])
        {
            loc_max2 = i;
        }
    }

    for(int i = 0, j = 0; i != loc_max1 + 1 || j != loc_max2 + 1; )
    {
        if(i != loc_max1 + 1 && j != loc_max2 + 1)
        {
            if(arr1[i] <= arr2[j])
            {
                printf("%d ", arr1[i++]);
            }
            else
            {
                printf("%d ", arr2[j++]);
            }
        }
        else if(i == loc_max1 + 1)
        {
            printf("%d ", arr2[j++]);
        }
        else
        {
            printf("%d ", arr1[i++]);
        }
    }
    
    for(int i = loc_max1 + 1, j = loc_max2 + 1; i != num1 || j != num2;)
    {
        if(i != num1 && j != num2)
        {
            if(arr1[i] >= arr2[j])
            {
                printf("%d ", arr1[i++]);
            }
            else
            {
                printf("%d ", arr2[j++]);
            }
        }
        else if(i == num1)
        {
            printf("%d ", arr2[j++]);
        }
        else
        {
            printf("%d ", arr1[i++]);
        }
    }
    return 0;
}