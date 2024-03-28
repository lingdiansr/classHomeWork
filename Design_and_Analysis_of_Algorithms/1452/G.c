/*
题目描述
给定一个只包含尖括号"<"和">"，小括号"("和")"，中括号"["和"]"，花括号"{"和"}"这八种符号的字符串（长度>=1）。
在字符串中括号可以任意嵌套，如果对应的左、右括号成对出现并且嵌套正确，则为一对可匹配括号。
匹配括号子串是指在一个括号串的一个子串（可以包含这个括号串自身）中，每一个括号都是可匹配括号。
编写一个程序计算一个输入字符串中最长匹配括号子串的长度。
输入
单组输入。
输入一个只包含上述八种左、右括号的字符串。（1≤ 字符串长度≤105）
输出
输出输入字符串中最长匹配括号子串的长度。
样例输入 Copy
<[({})][]()}{<>
样例输出 Copy
10*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 20
typedef struct tt
{
    char data[20];
    int top;
} sqStack;
void pushStack(sqStack *a, char value) // 入栈，从value读取值
{
    if (a->top == SIZE - 1)
    {
        return;
    }
    a->top++;
    a->data[a->top] = value;
}
void popStack(sqStack *a, char *value) // 入栈，将值存储到value
{
    if (a->top < 0)
    {
        return;
    }
    value = a->data[a->top];
    a->top--;
}
char readStackTop(sqStack *a)
{
    if (a->top < 0)
    {
        return 0;
    }

    return a->data[a->top];
}
int main()
{
    int n, count = 0, max = 0;
    char ch[100000], tmp;
    bool flag, f = false;
    sqStack s1 = {0, 0};
    s1.top = -1;
    gets(ch);
    for (int i = 0; ch[i] != '\0'; i++)
    {
        char n = ch[i];
        flag = (readStackTop(&s1) == '(') && (n == ')') 
        || (readStackTop(&s1) == '{') && (n == '}') 
        || (readStackTop(&s1) == '<') && (n == '>') 
        || (readStackTop(&s1) == '[') && (n == ']');
        // 三种括号有一种匹配就可出栈
        if (flag)
        {
            popStack(&s1, &tmp);
            if (f)
            {
                count += 2;
            }
            else
            {
                if (count > max)
                {
                    max = count;
                }
                count = 2;
            }
            f = true;
        }
        else
        {
            pushStack(&s1, n);
            f = false;
        }
    }
    printf("%d", max);
    return 0;
}