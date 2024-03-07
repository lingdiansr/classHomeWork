/*
题目描述
请使用递归编写一个程序求如下表达式的计算结果：
S(1) = 1/2
S(2) = 1/2 - 1/6
S(3) = 1/2 - 1/6 + 1/12
S(4) = 1/2 - 1/6 + 1/12 - 1/20
......
S(n) = 1/2 - 1/6 + 1/12 - 1/20 + 1/30 + ......
输入n (1<n<=100)，输出表达式S(n)的值（四舍五入，精确到小数点后六位）。
请编写一个递归程序实现该功能。
输入
单组输入，输入一个正整数n，1<n<=100。
输出
输出表达式S(n)的计算结果（四舍五入，精确到小数点后六位）。
样例输入 Copy
2
样例输出 Copy
0.333333
*/
#include <stdio.h>

double recursion(int n)
{
    if (n == 1)
    {
        return 1/2.0;
    }
    else
    {
        return recursion(n - 1) + (n % 2 == 0 ? -1.0 : 1.0) / (n * (n + 1));
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double result = recursion(n);
    printf("%.6f\n", result);

    return 0;
}
