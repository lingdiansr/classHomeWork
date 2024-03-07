/*题目描述
爱冒险的X星人在一艘海底沉船上发现了一串神秘数列，这个数列的前6项如下：
0 1 3 7 15 31
X星人对这串数列产生了浓厚的兴趣，他希望你能够帮他发现这个神秘数列中所蕴含的规律，并且使用递归来编写一个程序输出该数列前N项的和。
当输入一个正整数N时，请输出这个神秘数列前N项的和。
输入
单组输入，每组输入一个正整数N（N<=20）。
输出
输出一个正整数，对应这个神秘数列前N项的和。
样例输入 Copy
6
样例输出 Copy
57
*/
#include <stdio.h>
#include <math.h>
int recursion(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return recursion(n - 1) + pow(2, n - 1) - 1;
    }
}
int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d", recursion(n));
    return 0;
}