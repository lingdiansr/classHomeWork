/*题目描述
输入一个整数数组，请求出该数组的第k大元素。要求时间复杂度为O(n)。

输入
每组输入包括两行，第一行为k值；第二行为一个整数数组，两个数字之间用空格隔开。数组中元素个数小于1000。
输出
输出第k大元素的值，每个结果占一行
样例输入 Copy
2
3 2 1 5 6 4
样例输出 Copy
5*/

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
        return num[p];
    int i = pra(num, p, q);
    int j = i - p + 1;
    if (k == j)
        return num[i];
    else if (k < j)
        return qselect(num, p, i - 1, k);
    else
        return qselect(num, i + 1, q, k - j);
}

int main(int argc, const char *argv[])
{
    int num[1000];
    int k, n;
    while (~scanf("%d", &k))
    {

        n = 0;
        while (~scanf("%d", &num[n]))
        {
            n++;
            if (getchar() == '\n')
            {
                break;
            }
        }
        printf("%d\n", qselect(num, 0, n - 1, n - k + 1));
    }

    return 0;
}