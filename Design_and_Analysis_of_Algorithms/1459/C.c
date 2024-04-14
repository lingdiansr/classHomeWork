/*题目描述
HNUCM的小明同学特别喜欢下围棋。
一天他盯着围棋棋盘，想到这么一个问题：
有一个矩形棋盘，该棋盘跟围棋棋盘相似，由一个个正方形的小方格组成，小方格一共有n行，每行有m个小方格。如果将一个棋子放在左上角第1行第1列的格子中，每次走一步，但是每步只能朝右或者朝下走一格。
请问从左上角的方格（即第1行第1列）走到右下角（即第n行第m列）的方格，一共有多少条不同的路径？
输入
单组输入。
输入两个正整数n和m，分别表示棋盘的行数和列数，n和m均不超过100，两者之间用1个英文空格隔开。
输出
输出从左上角到右下角满足条件的不同路径数量。答案对1e9+7取模
样例输入 Copy
2 3
样例输出 Copy
3*/
#include <stdio.h>
int countPaths(int n, int m)
{
    int dp[n][m];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (int)(1e9+7);
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int result = countPaths(n, m);
    printf("%d\n", result);

    return 0;
}
