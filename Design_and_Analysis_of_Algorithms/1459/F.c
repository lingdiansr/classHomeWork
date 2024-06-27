/*题目描述
XP学长觉得矩阵很美，虽然他也不知道美在哪里，因此，他决定挖掘一下矩阵的
美。现在给定一个m行n列的矩阵，从左上角开始每次只能向右或者向下移动，最后
到达右下角的位置，将路径上的所有数字累加起来作为这条路径的路径和。XP学长
决定编写一个程序来求所有路径和中的最小路径和。例如，下面矩阵中的路径
1-3-1-0-6-1-0是所有路径中路径和最小的，返回结果是12。
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0

输入
输入包含多组测试用例，第一行输入一个T表示测试数据组数，(1<=T<=15)
接下来有T组数据，每组先输入两个整数M,N接下来输入M*N的矩阵(1<=N,M<=1000)，且最终结果在int范围内。
输出
输出路径和的最小值。
样例输入 Copy
1
4 4
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
样例输出 Copy
12*/
#include <stdio.h>
#include <stdlib.h>

int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    if (gridSize == 0)
        return 0;

    int m = gridSize;
    int n = *gridColSize;
    int **dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int *)malloc(n * sizeof(int));
    }

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = grid[i][j] + fmin(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int result = dp[m - 1][n - 1];

    for (int i = 0; i < m; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int m, n;
        scanf("%d %d", &m, &n);

        int **grid = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
        {
            grid[i] = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }

        int result = minPathSum(grid, m, &n);
        printf("%d\n", result);

        for (int i = 0; i < m; i++)
        {
            free(grid[i]);
        }
        free(grid);
    }

    return 0;
}
