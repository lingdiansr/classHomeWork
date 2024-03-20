/*
题目描述
从键盘上输入10个整数，用冒泡法对这10个数进行排序（由小到大）。【必须使用冒泡排序实现】
输入
以空格分隔的10个整数
输出
依次输出排好序的10个整数，每个数占一行。
样例输入 Copy
1 3 5 7 9 2 4 6 8 0
样例输出 Copy
0
1
2
3
4
5
6
7
8
9
*/
#include <stdio.h>
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
