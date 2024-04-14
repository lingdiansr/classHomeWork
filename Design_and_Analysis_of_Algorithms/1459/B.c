/*题目描述
如下图所示的数字三角形，从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，和最大的路径称为最佳路径。编写一个程序求出最佳路径上的数字之和。 【使用动态规划法实现】


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
路径上的每一步只能从一个数走到下一层上和它最近的左边的数或者右边的数。*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int **triangle = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
        {
            triangle[i] = (int *)malloc((i + 1) * sizeof(int));
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &triangle[i][j]);
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        printf("%d\n", triangle[0][0]);
    }
    return 0;
}
