/*
题目描述
编写一个程序，将两个有序数组合并成一个更大的有序数组，要求时间复杂度为O(n)。
输入
多组数据输入，每组输入包括两行，每行第一个数字为数组长度n，然后输入n个有序整数。
输出
输出合并后的数组（升序），每组输出用一个空行隔开。
样例输入 Copy
3 1 3 5
3 2 4 6
2 1 2
4 3 4 5 6
样例输出 Copy
1 2 3 4 5 6

1 2 3 4 5 6
*/
#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
        }
        else
        {
            printf("%d ", arr2[j]);
            j++;
        }
    }

    while (i < n1)
    {
        printf("%d ", arr1[i]);
        i++;
    }

    while (j < n2)
    {
        printf("%d ", arr2[j]);
        j++;
    }

    printf("\n");
}

int main()
{
    int n1, n2;

    while (~scanf("%d", &n1) )
    {
        int arr1[n1];
        for (int i = 0; i < n1; i++)
        {
            scanf("%d", &arr1[i]);
        }

        scanf("%d", &n2);
        int arr2[n2];
        for (int i = 0; i < n2; i++)
        {
            scanf("%d", &arr2[i]);
        }

        mergeArrays(arr1, n1, arr2, n2);
        printf("\n");
    }

    return 0;
}
