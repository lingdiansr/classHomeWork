/*题目描述
有一个rand(n)的函数，它的作用是产生一个在[0,n)的随机整数。现在有另外一个函数，它的代码如下：
int random(int n, int m)
{
    return rand(n)+m;
}
显而易见的是函数random(n,m)可以产生任意范围的随机数。现在问题来了，
如果我想要产生范围在[a,b)内的一个随机数，那么对应的n，m分别为多少？
输入
输入的第一行为一个正整数T (T<=1000)，表示一共有T组测试数据。
对于每组测试数据包含两个整数a，b (a<=b)。
输出
对于每组测试数据，输出一行包含两个整数n和m，两个整数中间有一个空格分隔。
样例输入 Copy
2
0 5
1 4
样例输出 Copy
5 0
3 1*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    int num, a, b;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d %d\n", b - a, a);
    }

    return 0;
}