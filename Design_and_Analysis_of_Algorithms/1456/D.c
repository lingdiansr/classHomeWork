/*
题目描述
在一个n×n (n = 2k)个方格组成的棋盘中，恰有一个方格与其他方格不同，称该方格为一特殊方格，且称该棋盘为一特殊棋盘。
在棋盘覆盖问题中，要用4种不同形态的L型骨牌覆盖给定的特殊棋盘上除特殊方格以外的所有方格，且任何2个L型骨牌不得重叠覆盖。


输入
多组测试用例，每组测试用例包括两部分，
第一部分为方格的宽度n，
第二部分则为方格，特殊方格为-1，其他方格为0。

输出
输出覆盖后的方案
样例输入 Copy
4
-1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
样例输出 Copy
-1 2 4 4
2 2 1 4
3 1 1 5
3 3 5 5*/

/*
16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 -1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*/
#include <stdio.h>
#include<stdlib.h>

int **board;
int tile = 1;

void cover(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;

    int t = tile++;
    int s = size / 2;

    // L型骨牌的四种形态
    if (dr < tr + s && dc < tc + s)
    {
        cover(tr, tc, dr, dc, s);
    }
    else
    {
        board[tr + s - 1][tc + s - 1] = t;
        cover(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    if (dr >= tr + s && dc < tc + s)
    {
        cover(tr + s, tc, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s - 1] = t;
        cover(tr + s, tc, tr + s, tc + s - 1, s);
    }

    if (dr < tr + s && dc >= tc + s)
    {
        cover(tr, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s - 1][tc + s] = t;
        cover(tr, tc + s, tr + s - 1, tc + s, s);
    }

    if (dr >= tr + s && dc >= tc + s)
    {
        cover(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        board[tr + s][tc + s] = t;
        cover(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        board = (int **)malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            board[i] = (int *)malloc(sizeof(int) * n);
        }

        int special_r, special_c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &board[i][j]);
                if (board[i][j] == -1)
                {
                    special_r = i;
                    special_c = j;
                }
            }
        }

        tile = 1;
        cover(0, 0, special_r, special_c, n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%2d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
