/*
题目描述
请设计一个算法，不排序，快速计算出一个无序数列的中位数。 时间复杂度要求为O(n)。
如果有奇数个元素，中位数则是数组排序后最中间的那个数字。
如果是偶数个元素，中位数则是数组排序后最中间两个元素的平均值。
输入
有多组输入，每组输入的第一行为n(1<=n<=1e5)，表示该数列的元素个数。
第二行为n个整数组成的无序数列
输出
每组样例输出一行，表示该无序数列的中位数。
若为偶数，请保留三位小数
若为奇数，直接输出
样例输入 Copy
5
5 3 2 1 4
样例输出 Copy
3*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int num[], int x, int y)
{
    int tmp = num[x];
    num[x] = num[y];
    num[y] = tmp;
}
int pra(int num[], int p, int q)
{
    srand((unsigned int)time(0));
    int x = rand() % (q - p + 1) + p;
    int i = p;
    swap(num, x, p);
    for (int j = p + 1; j <= q; j++)
    {
        if (num[j] <= num[p])
        {
            swap(num, ++i, j);
        }
    }
    swap(num, p, i);
    return i;
}
int qselect(int num[], int p, int q, int k)
{
    if (p == q)
    {
        return num[p];
    }
    if (p < q)
    {
        int i = pra(num, p, q);
        int j = i - p + 1;
        if (k <= j)
        {
            qselect(num, p, i, k);
        }
        else
        {
            qselect(num, i + 1, q, k - j);
        }
    }
}
int main(int argc, const char *argv[])
{
    int *num, n;
    while (~scanf("%d", &n))
    {
        num = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        if (n % 2 == 0)
        {
            printf("%.3f\n", (qselect(num, 0, n - 1, n / 2) + qselect(num, 0, n - 1, n / 2 + 1)) / 2.0);
        }
        else
        {
            printf("%d\n", qselect(num, 0, n - 1, (n + 1) / 2));
        }
    }

    return 0;
}