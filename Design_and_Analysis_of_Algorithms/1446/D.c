/*题目描述
1, 2, 3...9 这九个数字组成一个分数，其值恰好为1/3，要求每个数字出现且只能出现一次，如何组合？编写程序输出所有的组合。
输入
无
输出
输出所有的结果，如果有多个，每条结果占一行。
结果的格式 : xxxx/xxxxx ，按照分子从小到大的顺序输出。*/
#include <stdio.h>
int number[2][2];
int i = 0;
void swapElements(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void cal(int num[])
{
    int a = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    int b = num[4] * 10000 + num[5] * 1000 + num[6] * 100 + num[7] * 10 + num[8];
    if (a * 3 == b)
    {
        number[i][0] = a;
        number[i][1] = b;
        i++;
        // printf("%d/%d\n", a, b);
    }
}
void prem(int num[], int start, int end)
{
    if (start == end)
    {
        cal(num);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swapElements(num + start, num + i);
            prem(num, start + 1, end);
            swapElements(num + start, num + i);
        }
    }
}
int main(int argc, const char *argv[])
{
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    prem(num, 0, 8);
    printf("%d/%d\n", number[1][0], number[1][1]);
    printf("%d/%d\n", number[0][0], number[0][1]);
    return 0;
}