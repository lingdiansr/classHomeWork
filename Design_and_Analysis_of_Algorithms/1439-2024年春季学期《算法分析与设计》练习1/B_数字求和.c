/*题目描述
使用递归编写一个程序，计算一个正整数中所有数字之和。例如输入234，输出9。
输入
多组输入，每组输入一个正整数。
输出
输出结果，每个结果占一行。
样例输入 Copy
234
样例输出 Copy
9
*/
#include <stdio.h>
int every_sum(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return num % 10 + every_sum(num / 10);
}
int main(int argc, const char *argv[])
{
    int num;
    while (~scanf("%d",&num))
    {
        printf("%d\n", every_sum(num));
    }
    
    return 0;
}