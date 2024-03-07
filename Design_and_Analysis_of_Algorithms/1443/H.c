/*
题目描述
使用递归编写一个程序实现汉诺塔问题，要求在输入圆盘数量之后，输出圆盘的移动步骤，输出格式示例如下：
第1步:1号盘从A柱移至B柱
第2步:2号盘从A柱移至C柱


输入
多组测试用例，每组输入一个正整数n，n代表圆盘数量。
输出
每组输出之间有一行空行。

样例输入 Copy
3
样例输出 Copy
第1步:1号盘从A柱移至C柱
第2步:2号盘从A柱移至B柱
第3步:1号盘从C柱移至B柱
第4步:3号盘从A柱移至C柱
第5步:1号盘从B柱移至A柱
第6步:2号盘从B柱移至C柱
第7步:1号盘从A柱移至C柱*/ \
#include<stdio.h>

int step = 0;

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        step++;
        printf("第%d步:%d号盘从%c柱移至%c柱\n", step, n, A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        step++;
        printf("第%d步:%d号盘从%c柱移至%c柱\n", step, n, A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        step = 0;
        hanoi(n, 'A', 'B', 'C');
        printf("\n");
    }
    return 0;
}
