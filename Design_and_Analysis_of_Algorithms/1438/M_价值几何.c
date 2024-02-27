/*题目描述
鸡兔共笼问题是一个非常经典的数学问题。
现在告诉你笼子中的鸡和兔共有m只，脚共有n只，且已知鸡的价格为每只100元，兔子的价格为每只150元。
请问这一笼鸡和兔共值多少钱？
如果问题无解则输出“No solution”。
1<=m<=1000，1<=n<=1000。
输入
两个整数m和n（意义如题目描述所示），用空格分隔
输出
如果问题有解，则输出一个整数，表示这一笼鸡和兔共值多少钱。
如果问题无解，则输出“No solution”（没有引号）
样例输入 Copy
5 16
样例输出 Copy
650*/
#include <stdio.h>

int main(int argc, const char *argv[])
{
    double c_num, r_num;
    int num, feet_num;
    int value;
    scanf("%d %d", &num, &feet_num);
    c_num = (4 * num - feet_num) / 2.0;
    r_num = (feet_num - 2 * num) / 2.0;
    if (c_num - (int)c_num > 0 || r_num - (int)r_num > 0 || c_num < 0 || r_num < 0)
    {
        printf("No solution\n");
    }
    else
    {
        printf("%d", (int)c_num * 100 + (int)r_num * 150);
    }

    return 0;
}