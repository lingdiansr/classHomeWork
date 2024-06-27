/*题目描述
输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
90~100为A;
80~89为B;
70~79为C;
60~69为D;
0~59为E;
输入
输入数据有多组，每组占一行，由一个整数组成。
输出
对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。
样例输入 Copy
56
67
100
123
样例输出 Copy
E
D
A
Score is error!*/ \
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int score;
    while (~scanf("%d", &score))
    {
        if (score < 0 || score > 100)
        {
            printf("Score is error!\n");
        }
        else
        {
            if (score >= 90)
            {
                printf("A\n");
            }
            else if (score >= 80)
            {
                printf("B\n");
            }
            else if (score >= 70)
            {
                printf("C\n");
            }
            else if (score >= 60)
            {
                printf("D\n");
            }
            else
            {
                printf("E\n");
            }
        }
    }
    return 0;
}