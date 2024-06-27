/*
题目描述
编程实现快速排序算法，深入理解快速排序算法的基本思想。
输入
多组输入，每组第一个数字为数组长度，然后输入一个一维整型数组。
输出
输出快速排序之后的一维整型数组（升序）
样例输入 Copy
6 1 8 6 5 3 4
5 12 42 2 5 8
样例输出 Copy
1 3 4 5 6 8
2 5 8 12 42*/
#include<stdio.h>
#include<stdlib.h>
void swap(int num[],int x,int y){
    int tmp;
    tmp = num[x];
    num[x] = num[y];
    num[y] = tmp;
}
int Pa(int num[], int p, int r)
{
    int x = num[p];
    int i = p, j = p + 1;
    for (; j <= r; j++)
    {
        if (x > num[j])
        {
            swap(num, ++i, j);
        }
    }
    swap(num, p, i);
    return i;
}
void QuickSort(int num[], int p, int r)
{
    if (p<r)
    {
        int mid = Pa(num, p, r);
        QuickSort(num, p, mid - 1);
        QuickSort(num, mid + 1, r);
    }
    
}
int main(int argc, const char* argv[]) {
    int n, *num;
    while (~scanf("%d",&n))
    {
        num = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        QuickSort(num, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    
    return 0;
}