/*
题目描述
使用分治算法实现两个大整数相乘。
输入
两个十进制大整数，满足每一个整数长度为2^n且两个大整数的长度相等。（多组数据）

输出
两个大整数的乘积。
样例输入 Copy
1234 5678
样例输出 Copy
7006652
*/ \
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int judge = 0;

char *add(char *X, char *Y)
{
    int i = strlen(X) - 1;
    int j = strlen(Y) - 1;
    int add = 0;
    char sum[100] = "";

    while (i >= 0 || j >= 0 || add != 0)
    {
        if (i >= 0)
            add += X[i--] - '0';
        if (j >= 0)
            add += Y[j--] - '0';

        char temp[2];
        sprintf(temp, "%d", add % 10);
        strcat(sum, temp);
        add /= 10;
    }

    char *result = (char *)malloc(strlen(sum) + 1);
    strcpy(result, strrev(sum));

    return result;
}

char *largeInt(char *X, char *Y)
{
    if (strlen(X) == 0 || strlen(Y) == 0)
    {
        char *result = (char *)malloc(2);
        strcpy(result, "0");
        return result;
    }

    if (X[0] == '-')
    {
        X = X + 1;
        judge++;
    }

    if (Y[0] == '-')
    {
        Y = Y + 1;
        judge++;
    }

    int x = strlen(X);
    int y = strlen(Y);

    if ((x <= 1 || y <= 1) && (x + y < 5))
    {
        int n = atoi(X);
        int m = atoi(Y);
        char *result = (char *)malloc(20);
        sprintf(result, "%d", n * m);
        return result;
    }

    char A[50], B[50], C[50], D[50];
    strncpy(A, X, x - x / 2);
    A[x - x / 2] = '\0';
    strncpy(B, X + x - x / 2, x / 2);
    B[x / 2] = '\0';
    strncpy(C, Y, y - y / 2);
    C[y - y / 2] = '\0';
    strncpy(D, Y + y - y / 2, y / 2);
    D[y / 2] = '\0';

    char *AC = largeInt(A, C);
    char *BD = largeInt(B, D);
    char *AD = largeInt(A, D);
    char *BC = largeInt(B, C);

    int xy0 = x / 2 + y / 2;
    int x0 = x / 2;
    int y0 = y / 2;

    for (int i = 0; i < xy0; i++)
        strcat(AC, "0");
    for (int i = 0; i < x0; i++)
        strcat(AD, "0");
    for (int i = 0; i < y0; i++)
        strcat(BC, "0");

    char *sum = add(AC, AD);
    sum = add(sum, BC);
    sum = add(sum, BD);

    free(AC);
    free(BD);
    free(AD);
    free(BC);

    return sum;
}

int main()
{
    char X[100], Y[100];
    while (~scanf("%s %s", X, Y))
    {

        char *sum = largeInt(X, Y);

        if (judge % 2 != 0)
        {
            char *temp = (char *)malloc(strlen(sum) + 2);
            temp[0] = '-';
            strcpy(temp + 1, sum);
            sum = temp;
        }

        printf("%s\n", sum);

        free(sum);
    }
    
    return 0;
}
