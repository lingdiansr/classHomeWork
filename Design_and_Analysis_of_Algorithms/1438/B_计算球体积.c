/*题目描述
根据输入的半径值，计算球的体积。
输入
输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
输出
输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
样例输入 Copy 1 1.5 样例输出 Copy 4.189 14.137 提示
#define PI 3.1415927*/
#include <stdio.h>
#define PI 3.1415927

int main(int argc, const char *argv[])
{
    double r;
    while (~scanf("%lf", &r))
    {
        printf("%.3lf\n", PI * r * r * r * 4 / 3);
    }
    return 0;
}