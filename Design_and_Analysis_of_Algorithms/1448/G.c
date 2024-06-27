/*题目描述
设a[0:n-1]是已排好序的数组（数组元素不重复）。请改写二分搜索算法，使得当待搜索元素x不在数组中时，
返回小于x的最大元素的位置i和大于x的最小元素的位置j；当待搜索元素x在数组中时，返回的i和j相同，均为x在数组中的位置
输入
多组数据输入，每组第一个数字为数组的长度n，然后输入n个整数，最后输入带查询的值x。
输出
输出小于x的最大元素的位置i和大于x的最小元素的位置j；当待搜索元素x在数组中时，返回的i和j相同，均为x在数组中的位置
样例输入 Copy
3 1 2 3 2
4 0 1 3 4 2
样例输出 Copy
2 2
2 3*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int n, *num, s;
    while (~scanf("%d", &n))
    {
        num = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        scanf("%d", &s);
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (right + left) / 2;

            if (num[mid] == s)
            {
                left = right = mid;
                break;
            }
            else if (num[mid] < s)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        printf("%d %d\n", right+1, left+1);
    }
    return 0;
}