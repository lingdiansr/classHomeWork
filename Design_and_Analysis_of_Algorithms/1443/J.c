/*
题目描述
喜欢探险的Kimi同学在一个山洞中发现了一串神秘的数，这串数的前七项如下：
1, 1, 8, 22, 85, 281, 988, ......
Kimi很想知道这个神秘数列中所蕴含的规律，你能否编写一个程序帮帮他。
当输入一个正整数N时，输出这个神秘数列第N项的值。
输入
单组输入。
输入一个正整数N，N<=50。

输出
输出神秘数列的第N项的值。
样例输入 Copy
8
样例输出 Copy
3382*/ \
#include<stdio.h>

int main()
{
    int n;
    long long nums[50];
    scanf("%d", &n);
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        nums[i] = 5 * nums[i - 2] + 2 * nums[i - 1] + 1;
    }

    printf("%lld", nums[n]);

    return 0;
}
