/*题目描述
小米同学最近在学习进制转换。众所周知，在表示十六进制数时，除了0-9这九个阿拉伯数字外，还引入了“A”、“B”、“C”、“D”、“E”和“F”这六个英文字母（不区分大小写）。
现在给你一个十进制正整数，请问在将其转换为十六进制之后，对应的十六进制表示中有多少位是字母？
输入
单组输入。
输入一个十进制正整数N（N<=10^6）。
输出
输出将N转换成十六进制数字后所包含的字母位的数量，如果没有字母位则输出0。
样例输入 Copy
20
样例输出 Copy
0*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    long long n;
    int count = 0;
    scanf("%lld", &n);
    do
    {
        if (n%16>9)
        {
            count++;
        }
        
    } while (n/=16);
    printf("%d", count);
    return 0;
}