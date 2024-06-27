/*题目描述
爱冒险的X星人在一艘海底沉船上发现了一串神秘数列，这个数列的前8项如下：
5, 8, 18, 34, 70, 138, 278, 554
X星人对这串数列产生了浓厚的兴趣，他希望你能够帮他发现这个神秘数列中所蕴含的规律，并且编写一个程序输出该数列前N项的和。
当输入一个正整数N时，请输出这个神秘数列前N项的和。

输入
单组输入，每组输入一个正整数N（N<=20）。
输出
输出一个正整数，对应这个数列前N项的和。
样例输入 Copy
4
样例输出 Copy
65*/
#include<stdio.h>

int num(int n){
    if (n > 1)
    {
        return 2 * num(n - 1) + (n % 2 == 0 ? -2 : 2);
    }
    else
    {
        return 5;
    }
}
int sum(int n){
    if (n>0)
    {
        return num(n) + sum(n - 1);
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    int index;
    scanf("%d", &index);
    printf("%d\n", sum(index));
    return 0;
}