/*
题目描述
Now, here is a function:
F(x) = 6*x^7+8*x^6+7*x^3+5*x^2-y*x (0 <= x <=100)
Can you find the minimum value when x is between 0 and 100.
输入
The first line of the input contains an integer T(1<=T<=100) which means the number of test cases. Then T lines follow, each line has only one real numbers Y.(0 < Y <1e10)
输出
Just the minimum value (accurate up to 4 decimal places),when x is between 0 and 100.
样例输入 Copy
2
100
200
样例输出 Copy
-74.4291
-178.8534
提示
凸函数和凹函数求极值可以用三分查找来实现。*/
#include <stdio.h>
#include <math.h>
double fun(double x, int y)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}
int main(int argc, const char *argv[])
{
    int n, y;
    double f;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y);
        double left = 0, right = 100;
        while (right - left > 1e-9)
        {
            double x1 = left + (right - left) / 3;
            double x2 = right - (right - left) / 3;
            if (fun(x1, y) < fun(x2, y))
            {
                right = x2;
            }
            else
            {
                left = x1;
            }
        }
        printf("%.4lf\n", fun(left, y));
    }

    return 0;
}