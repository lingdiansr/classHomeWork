/*
题目描述
使用分治算法实现两个大整数相乘。
输入
两个十进制大整数，满足每一个整数长度为2^n且两个大整数的长度相等。（多组数据）

输出
两个大整数的乘积。
样例输入 Copy
1234 5678
样例输出 Copy
7006652
*/ \
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int sign(long value)
{
    return value > 0 ? 1 : -1;
}
long solve(long x, long y, int n)
{
    int s = sign(x) * sign(y);
    x = abs(x);
    y = abs(y);
    if (x == 0 || y == 0)
        return 0;
    else if (n == 1)
        return s * x * y;
    else
    {
        long A = (long)(x / pow(10, n / 2));
        long B = (x % (long)pow(10, n / 2));
        long C = (long)(y / pow(10, n / 2));
        long D = (y % (long)pow(10, n / 2));
        long AC = solve(A, C, n / 2);
        long BD = solve(B, D, n / 2);
        long ABCD = solve((A - B), (D - C), n / 2) + AC + BD;
        return (long)(s * (AC * pow(10, n) + ABCD * pow(10, n / 2) + BD));
    }
}
char *mutiply(char a[], char b[])
{
}
int main()
{
    long X, Y, result;
    while (~scanf("%ld %ld", &X, &Y))
    {
        result = solve(X, Y,(int)log10(X)+1);
        printf("%ld\n",result);
    }
    return 0;
}
