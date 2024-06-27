/*题目描述
使用备忘录法编写一个程序，求一个正整数n的所有划分个数。
例如，输入3，输出3；输入4，输出5。
输入
多组输入，每一组是一个正整数n。
输出
输出划分数。
样例输入 Copy
3
4
样例输出 Copy
3
5
*/
#include <stdio.h>
#include <stdlib.h>
int **numbers;
int pra(int n, int m)
{
    if (n < 1 || m < 1)
        return 0;
    if (n == 1 || m == 1)
        return 1;
    if (n < m)
        return pra(n, n);
    if (n == m)
    {
        if (numbers[n - 1][n - 2] == 0)
        {
            numbers[n - 1][n - 2] = pra(n, n - 1);
        }
        return 1 + numbers[n - 1][n - 2];
    }
    if (n > m)
    {
        if (numbers[n - 1][m - 2] == 0)
            numbers[n - 1][m - 2] = pra(n, m - 1);
        if (numbers[n - m - 1][m - 1] == 0)
            numbers[n - m - 1][m - 1] = pra(n - m, m);
        return numbers[n - 1][m - 2] + numbers[n - m - 1][m - 1];
    }
}
int main(int argc, const char *argv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        numbers = (int **)malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            numbers[i] = (int *)malloc(sizeof(int) * n);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                numbers[i][j] = 0;
            }
            
        }
        
        printf("%d\n", pra(n, n));
    }

    return 0;
}