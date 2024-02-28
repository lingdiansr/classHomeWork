/*题目描述
N个（3<=N<=1000）X星人站成一行，每个X星人的身高都是一个正整数（范围：100-300，单位：厘米）。
计算相邻两个X星人的身高差（身高差为非负数），其中最大的身高差称为最萌身高差。请编写一个程序输出由N个X星人排成的这一行的最萌身高差。
输入
单组输入。
第1行输入一个正整数N（3<=N<=1000）。
第2行输入N个正整数，分别表示每一个X星人的身高，每一个正整数的范围为[100, 300]，两两之间用英文空格隔开。
输出
输出一个非负整数表示这一行X星人的最萌身高差。
样例输入 Copy
5
120 178 156 172 200
样例输出 Copy
58*/ 
#include<stdio.h>
#include<math.h>
int main(int argc, const char *argv[])
{
    int moe=0, moe_hight, num;
    int height;
    scanf("%d", &num);
    scanf("%d", &moe_hight);
    for (int i = 1; i < num; i++)
    {
        scanf("%d", &height);
        if (abs(height - moe_hight) > moe)
        {
            moe = abs(height - moe_hight);
        }
        moe_hight = height;
    }
    printf("%d\n", moe);
    return 0;
}
