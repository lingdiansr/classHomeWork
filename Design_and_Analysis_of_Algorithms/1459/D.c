/*
题目描述
某滚球游戏规则如下：球从入口处（第一层）开始向下滚动，每次可向下滚动一层，直到滚至最下面一层为止。球每次可滚至左下、下方或右下三个方格中的任意一个，每个方格都有一个得分，如样例所示。第1层有1个方格，第2层有3个方格，……，以此类推，第n层有2*n-1个方格。设计一个算法，使得球从入口滚至最下面一层的总得分和最大。
输入
对于每个样例，第1行的正整数n表示数字三角形的行数。（n<=100)
接下来n行包含一个数字三角形，每一行包含2*n-1个方格，对应有2*n-1个表示得分的正整数（不超过10^5），每两个数字之间用空格隔开。
每两组样例之间有一个空行。
输出
球从入口（第一层）滚至最下面一层的最大得分和。
样例输入 Copy
2
  3
2 1 3

3
    1
  2 1 2
3 4 2 1 3
样例输出 Copy
6
7*/
#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;

    while (scanf("%d", &n) == 1)
    {
        int **triangle = (int **)malloc(n * sizeof(int *));
        int **dp = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
        {
            triangle[i] = (int *)malloc((2 * i + 1) * sizeof(int));
            dp[i] = (int *)malloc((2 * i + 1) * sizeof(int));
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * i + 1; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }

        for (int j = 0; j < 2 * n - 1; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < 2 * i + 1; j++)
            {
                dp[i][j] = triangle[i][j] + max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j + 2]));
            }
        }

        printf("%d\n", dp[0][0]);
    }

    return 0;
}
