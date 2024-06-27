/*题目描述
给你n个整数，求他们中所有奇数的乘积。
输入
输入数据包含多个测试实例，每个测试实例占一行，
每行的第一个数为n，
表示本组数据一共有n个，接着是n个整数，
你可以假设每组数据必定至少存在一个奇数。
输出
输出每组数中的所有奇数的乘积，对于测试实例，输出一行。
样例输入 Copy
3 1 2 3
4 2 3 4 5
样例输出 Copy
3
15*/

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int n, num, res;
    while (~scanf("%d", &n))
    {
        res = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if (num % 2 != 0)
            {
                res *= num;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}