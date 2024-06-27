/*
题目描述
用大小为1×2的骨牌铺满一个大小为2×n的长方形方格，编写一个程序，输入n，输出铺放方案总数。例如，输入n=3，即大小为2×3的方格，输出3。3种骨牌铺放方案如下图所示：

输入
多组测试用例，每一组是一个正整数。
输出
每组输出占一行。
只需要输出铺放方案总数，不需要输出具体的铺放方案。
样例输入 Copy
3
样例输出 Copy
3
*/
#include <stdio.h>
int fun(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return fun(n - 1) + fun(n - 2);
    }
}
int main(int argc, const char *argv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", fun(n));
    }

    return 0;
}