#include <stdio.h>

void find_partitions(int n, int start, int* partition, int index) 
{
    // 如果n为0，输出当前的分解
    if (n == 0) 
    {
        for (int i = 0; i < index; i++) 
        {
            printf("%d ", partition[i]);
        }
        printf("\n");
        return;
    }
    // 从start开始，递归进行分解
    for (int i = start; i <= n; i++) 
    {
        partition[index] = i;  // 选择i
        find_partitions(n - i, i, partition, index + 1);  // 递归
    }
}

int main() 
{
    int n = 0;
    scanf("%d", &n);
    int partition[30] = {0};  // 最多分解为30个数
    find_partitions(n, 1, partition, 0);
    return 0;
}
