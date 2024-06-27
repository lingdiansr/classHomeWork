/*题目描述
使用非递归算法，实现二分搜索。
输入
多组数据输入，每组第一个数字为数组的长度n，然后输入n个整数，最后输入待查询的值。
输出
输出待查询值所在的位置，如果没有找到，则返回-1。
样例输入 Copy
3 1 2 3 2
4 0 1 3 4 2
样例输出 Copy
2
-1*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int n, *num, s, r;
    while (~scanf("%d", &n))
    {
        num = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        scanf("%d", &s);
        int start = 0, end = n - 1;
        r = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (num[mid] == s)
            {
                r = mid;
                break;
            }
            else if (num[mid] < s)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        printf("%d\n", r != -1 ? r + 1 : r);
    }

    return 0;
}