/*
题目描述
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。

输入
多组数据输入，每组数据包含两个正整数a, b，且 a<b。
输出
蜜蜂从蜂房a爬到蜂房b的可能路线数。
样例输入 Copy
1 2
3 4
样例输出 Copy
1
1*/
#include <stdio.h>
int fun(int n){
    if (n<3)
    {
        return 1;
    }else
    {
        return fun(n - 1) + fun(n - 2);
    }
}
int main(int argc, const char *argv[])
{
    int a, b, n;
    if (a>b)
    {
        n = a;
        a = b;
        b = a;
    }

    while (~scanf("%d %d", &a, &b))
    {
        printf("%d\n", fun(b -a + 1));
    }

    return 0;
}