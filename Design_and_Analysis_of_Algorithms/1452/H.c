/*
题目描述
考试题目和要点：
1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。
2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。
3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。
输入
多组输入。输入一个double数。
输出
输出人民币格式。

样例输入 Copy
151121.15
样例输出 Copy
人民币拾伍万壹仟壹佰贰拾壹元壹角伍分
提示
10.56 读作人民币拾元伍角陆分
30005007 读作 三千万五千零七
30025007 读作 三千零二万五千零七
30020507 读作 三千零二万零五百零七

*/
#include <stdio.h>
#include <string.h>

char *digits[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
char *units[] = {"", "拾", "佰", "仟", "万", "亿"};

void printChinese(double num)
{
    int integer = (int)num;
    int decimal = (int)((num - integer) * 100);

    printf("人民币");

    // 处理整数部分
    if (integer == 0)
    {
        printf("零");
    }
    else
    {
        int divisor = 1000000000;
        int printedZero = 0;
        for (int i = 0; i < 10; i++)
        {
            int current = integer / divisor % 10;
            if (current != 0)
            {
                if (printedZero)
                {
                    printf("零");
                    printedZero = 0;
                }
                printf("%s%s", digits[current], units[i % 4]);
            }
            else
            {
                printedZero = 1;
            }

            if (i % 4 == 0 && i != 0)
            {
                printf("%s", units[4 + i / 4]);
            }
            divisor /= 10;
        }
        printf("元");
    }

    // 处理小数部分
    if (decimal == 0)
    {
        printf("整");
    }
    else
    {
        printf("%s%s分", digits[decimal / 10], digits[decimal % 10]);
    }

    printf("\n");
}

int main()
{
    // system("chcp 65001");
    double num;
    while (~scanf("%lf", &num))
    {
        printChinese(num);
    }
    return 0;
}
