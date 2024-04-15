/*
题目描述
小X在挑战一个收集金币的游戏。
已知有一个由若干小方格组成的矩形区域，一共包含M行和N列。每一个小方格中都有一个正整数，表示该方格中的金币数目。
现在小X从最上面的行（第1行）任选一个方格作为出发点，每一次只能向正下方、左下方或者右下方走一格，但不能走出矩形区域，最终要到达矩形区域的最后一行。
小X每走一格就会收集该方格中的全部金币。
请你编写一个程序，输出小X最多可以收集多少枚金币？（包含起始方格和结束方格中所包含的金币）。
输入
单组输入。
第1行输入两个正整数M和N，分别表示矩形区域的行和列，M和N均不超过1000，两者之间用一个英文空格隔开。
接下来M行，每行包含N个正整数，每个正整数表示对应方格中的金币数，每个方格中的金币数均不超过100。同一行的两个正整数之间用一个英文空格隔开。
输出
输出一个正整数，表示小X从第1行到最后一行能够收集到的最多金币数。
样例输入 Copy
3 3
2 1 1
8 5 9
2 1 10
样例输出 Copy
20*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    int **grid = (int **)malloc(M * sizeof(int *));
    int **dp = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++)
    {
        grid[i] = (int *)malloc(N * sizeof(int));
        dp[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &grid[i][j]);
            dp[0][j] = grid[0][j];
        }
    }

    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = grid[i][j];
            if (j == 0)
            {
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
            else if (j == N - 1)
            {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] += max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
            }
            // dp[i][j] = grid[i][j];
            // if (j > 0)
            // {
            //     dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            // }
            // if (j < N - 1)
            // {
            //     dp[i][j] += max(dp[i - 1][j], dp[i - 1][j + 1]);
            // }
        }
    }

    int maxCoins = dp[M - 1][0];
    for (int i = 1; i < N; i++)
    {
        maxCoins = max(maxCoins, dp[M - 1][i]);
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    
    printf("%d\n", maxCoins);

    for (int i = 0; i < M; i++)
    {
        free(grid[i]);
        free(dp[i]);
    }
    free(grid);
    free(dp);

    return 0;
}
