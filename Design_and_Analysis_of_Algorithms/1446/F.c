/*题目描述
编写一个程序，使用递归算法输出一个一维字符数组中所有字符的全排列，假设字符都不一样。例如{'a','b','c'}的全排列为(a,b,c), (a,c,b), (b,a,c), (b,c,a), (c,a,b), (c,b,a)
输入
多组测试用例，每组输入一个正整数n(0<n<=26)。
输出
输出从a开始，连续n个字母的全排列，且每组输出之间用空格隔开。
样例输入 Copy
1
2
样例输出 Copy
a

ab
ba*/

#include <stdio.h>
#include <string.h>
void swapElements(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void cal(char str[])
{
    // for (int i = 0; str[i]!=; i++)
    // {
    //     /* code */
    // }
    puts(str);
}
void prem(char str[], int start, int end)
{
    if (start == end)
    {
        cal(str);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swapElements(str + start, str + i);
            prem(str, start + 1, end);
            swapElements(str + start, str + i);
        }
    }
}
int main(int argc, const char *argv[])
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    int n;
    while (~scanf("%d", &n))
    {
        str[n] = '\0';
        prem(str, 0, n-1);
        printf("\n");
        // puts(str);
        strcpy(str,"abcdefghijklmnopqrstuvwxyz");
    }

    return 0;
}