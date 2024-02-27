/*题目描述
2020年是HNUCM本科教育60周年，为了表达对HNUCM的爱意，TC希望你能够编写一个程序帮他表达心声。
输入一个正整数n（n<=100），输出n次“I love HNUCM.”。
输入
一个正整数n（n<=100）。
输出
n次“I love HNUCM.”。
样例输入 Copy
2
样例输出 Copy
I love HNUCM.
I love HNUCM.*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("I love HNUCM.\n");
    }

    return 0;
}
