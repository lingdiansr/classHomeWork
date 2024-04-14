/*
题目描述
如下图所示的数字三角形，从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，和最大的路径称为最佳路径。编写一个程序求出最佳路径上的数字之和。 【使用备忘录法实现】

         7
       3   8
     8   1   2
   2   7   4   4
4    5   2   6   5


输入
多组样例输入，每组第一行输入三角形的层数n，接下来n行输入三角形。
输出
输出最佳路径上的数字之和。
样例输入 Copy
2
1
1 2
3
1
1 2
1 2 3
样例输出 Copy
3
6
提示
路径上的每一步只能从一个数走到下一层中它下面的数或者右下角的数。*/
#include <stdio.h>
#include <stdlib.h>
int **triangle;
int **memo;

int max(int a, int b)
{
    return a > b ? a : b;
}

int bestPath(int n, int i, int j)
{
    if (i == n)
    {
        return 0;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int left = bestPath(n, i + 1, j);
    int right = bestPath(n, i + 1, j + 1);

    memo[i][j] = triangle[i][j] + max(left, right);

    return memo[i][j];
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        triangle = (int **)malloc(sizeof(int *) * n);
        memo = (int **)malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            triangle[i] = (int *)malloc(sizeof(int) * n);
            memo[i] = (int *)malloc(sizeof(int) * n);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
                memo[i][j] = -1;
            }
        }

        int result = bestPath(n, 0, 0);
        printf("%d\n", result);
    }

    return 0;
}
