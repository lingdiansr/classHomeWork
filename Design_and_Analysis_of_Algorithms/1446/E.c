/*题目描述
使用递归编写一个程序，求一个正整数n的所有划分个数。
例如，输入3，输出3；输入4，输出5。
输入
多组输入，每一组是一个正整数n。
输出
输出划分数。
样例输入 Copy
3
4
样例输出 Copy
3
5*/
#include <stdio.h>

int recursion(int n, int m)
{
    if (n == 1 || m == 1)
    {
        return 1;
    }
    if (n < m)
    {
        return recursion(n, n);
    }
    if (n == m)
    {
        return 1 + recursion(n, m - 1);
    }
    return recursion(n, m - 1) + recursion(n - m, m);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", recursion(n, n));
    }
    return 0;
}
