/*
题目描述
编写一个程序，使用分治策略实现二路归并排序（升序）。
输入
多组输入，每组第一个数字为数组长度，然后输入一个一维整型数组。
输出
输出排序之后（升序）的一维整型数组，每组输出占一行。
样例输入 Copy
6 1 8 6 5 3 4
5 12 42 2 5 8
样例输出 Copy
1 3 4 5 6 8
2 5 8 12 42*/
#include <stdio.h>
#include <stdlib.h>
void mergeArrays(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int num[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(num, l, mid);
        mergeSort(num, mid + 1, r);
        mergeArrays(num, l, mid, r);
    }
}
int main(int argc, const char *argv[])
{

    int n, *num;
    while (~scanf("%d", &n))
    {
        num = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        mergeSort(num, 0, n - 1);
        // mergeArrays(num, 0, n / 2, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
    }

    return 0;
}