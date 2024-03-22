/*题目描述
请编写一个程序，输入包含n（n<=100000）个整数的数列S以及包含q个(q<=50000)不重复整数的数列T，输出既包含于T也包含于S的整数的个数C。S、T中的元素均大于0且小于109。S的元素按升序排列，T的元素不重复。
输入
第一行输入n，第二行输入代表S的n个整数，第三行输入q，第四行输入代表T的q个整数。
输出
用1行输出C。
样例输入 Copy
5
1 2 3 4 5
3
3 4 1
样例输出 Copy
3*/
#include <stdio.h>
#include <stdlib.h>
int search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (right + left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main(int argc, const char *argv[])
{
    int n, q, count;
    int *s, *t;
    count = 0;
    scanf("%d", &n);
    s = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    t = (int *)malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < q; i++)
    {
        if (search(s, n, t[i]) != -1)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}