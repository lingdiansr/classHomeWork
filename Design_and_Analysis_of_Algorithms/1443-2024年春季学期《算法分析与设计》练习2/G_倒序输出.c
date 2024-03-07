/*题目描述
使用递归编写一个程序，逆序输出一个非负整数。例如输入1234，输出4321(不含前导0)。
输入
多组输入，每组输入一个非负整数。
输出
逆序输出结果，每个结果占一行。
样例输入 Copy
12
1230
0
样例输出 Copy
21
321
0*/

#include <stdio.h>
#include <math.h>
int recursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int pom = pow(10, (int)log10(n));
        int num = (n % 10) * pom;
        return recursion(n / 10) + num;
    }
}
int main(int argc, const char *argv[])
{
    int num;
    while (~scanf("%d", &num))
    {
        printf("%d\n", recursion(num));
    }
    return 0;
}