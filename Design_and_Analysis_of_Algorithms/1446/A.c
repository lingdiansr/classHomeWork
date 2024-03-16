/*题目描述
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 0 ；否则，返回 1 。
如果存在一个整数 x 使得n == 2x ，则认为 n 是 2 的幂次方。
请用递归编写一个程序来判断。
【友情提醒：请使用递归来实现】

输入
多组输入，每组输入一个非负整数，每组占一行
输出
输出结果，每个结果占一行
样例输入 Copy
1
16
3
4
5
样例输出 Copy
0
0
1
0
100*/
#include <stdio.h>
int recursion(int n, int pow)
{
    if (n > pow)
    {
        return recursion(n, pow * 2);
    }
    else
    {
        if (n == pow)
        {
            return 0;
        }else
        {
            return 1;
        }
        
    }
}
int main(int argc, const char *argv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", recursion(n, 1));
    }

    return 0;
}