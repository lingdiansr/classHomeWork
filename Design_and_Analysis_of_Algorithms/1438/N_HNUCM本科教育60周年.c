
/*题目描述
1960年是HNUCM的本科教育元年，今年是HNUCM创办本科教育60周年。
现在需要在一个大型LED显示屏上显示60两个数字。每个数字均占5行，但是所占列的数量由用户输入。
例如当用户输入4时，输出结果如下：
1111  1111
1000  1001
1111  1001
1001  1001
1111  1111
当用户输入6时，输出结果如下：
111111  111111
100000  100001
111111  100001
100001  100001
111111  111111
两个数字之间用两个空格隔开。
观察上述两组输出的规律，然后编写一个程序，输入每个数字所占列数n(3<=n<=10)，输出60对应的字符画。
输入
一个正整数n，如题所示
输出
根据题目描述，写出60对应的字符画
样例输入 Copy
4
样例输出 Copy
1111  1111
1000  1001
1111  1001
1001  1001
1111  1111*/ 
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[100];
    char str1[100];

    for (int t = 1; t <= n - 2; t++)
    {
        str[t - 1] = '1';
    }
    str[n - 2] = '\0';

    for (int t = 1; t <= n - 2; t++)
    {
        str1[t - 1] = '0';
    }
    str1[n - 2] = '\0';

    printf("1%s1  1%s1\n", str, str);
    printf("1%s0  1%s1\n", str1, str1);
    printf("1%s1  1%s1\n", str, str1);
    printf("1%s1  1%s1\n", str1, str1);
    printf("1%s1  1%s1\n", str, str);

    return 0;
}