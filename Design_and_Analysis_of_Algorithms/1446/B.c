/*题目描述
使用递归编写一个程序，求：
S(n)=1-1/2+1/3-1/4+1/5-1/6+......
输入
多组数据输入，每组输入一个正整数n。
输出
输出S(n)的计算结果（精确到小数点后六位）。
样例输入 Copy
1
样例输出 Copy
1.000000*/
#include <stdio.h>
int xi(int n)
{
    if (n % 2 == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
double recursion(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 1.0 / n * xi(n) + recursion(n - 1);
    }
}
int main(int argc, const char *argv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%.6lf\n", recursion(n));
    }

    return 0;
}