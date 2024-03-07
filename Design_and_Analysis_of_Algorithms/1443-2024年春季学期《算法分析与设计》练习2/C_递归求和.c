/*
题目描述
使用递归编写一个程序求如下表达式的计算结果：  (1<n<=20)
S(n) = 1*4 + 4*9 + 9*16 + 16*25 + ... + ((n-1)^2)*n^2
输入n，输出表达式S(n)的结果。
输入
单组输入，输入一个正整数n，1<n<=20。
输出
输出表达式S(n)的计算结果。
样例输入 Copy
3
样例输出 Copy
40
*/
#include <stdio.h>
int pow2(int n)
{
    return n * n;
}
int recursion(int n)
{
    if (n < 2)
    {
        return 0;
    }
    else
    {
        return pow2(n) * pow2(n - 1) + recursion(n - 1);
    }
}
int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d\n", recursion(n));
    return 0;
}