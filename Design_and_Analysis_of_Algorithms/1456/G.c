/*题目描述
输入两个实数，判断第一个数大，第二个数大还是一样大。每个数的格式为：

[整数部分].[小数部分]
简单起见，整数部分和小数部分都保证非空，且整数部分不会有前导 0。不过，小数部分的最 后可以有 0，因此 0.0和 0.000是一样大的。

输入
输入包含不超过 20组数据。每组数据包含一行，有两个实数（格式如前所述）。每个实数都 包含不超过 100个字符。

输出
对于每组数据，如果第一个数大，输出"Bigger"。如果第一个数小，输出"Smaller"。如果两个 数相同，输出"Same"。

样例输入 Copy
1.0 2.0
0.00001 0.00000
0.0 0.000
样例输出 Copy
Case 1: Smaller
Case 2: Bigger
Case 3: Same*/ \
#include<stdio.h>
#include <string.h>

// 比较两个实数的大小
int compareNumbers(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // 找到小数点的位置
    char *dot1 = strchr(num1, '.');
    char *dot2 = strchr(num2, '.');

    // 计算小数部分的长度
    int decimalLen1 = dot1 ? len1 - (dot1 - num1) - 1 : 0;
    int decimalLen2 = dot2 ? len2 - (dot2 - num2) - 1 : 0;
    int maxDecimalLen = decimalLen1 > decimalLen2 ? decimalLen1 : decimalLen2;

    // 将两个实数补齐小数部分长度
    char paddedNum1[200], paddedNum2[200];
    sprintf(paddedNum1, "%s", num1);
    sprintf(paddedNum2, "%s", num2);

    if (dot1)
    {
        for (int i = decimalLen1; i < maxDecimalLen; i++)
        {
            strcat(paddedNum1, "0");
        }
    }
    if (dot2)
    {
        for (int i = decimalLen2; i < maxDecimalLen; i++)
        {
            strcat(paddedNum2, "0");
        }
    }

    // 比较两个补齐后的实数
    return strcmp(paddedNum1, paddedNum2);
}

int main()
{
    char num1[100], num2[100];
    int caseNum = 1;

    // 循环读取输入数据并比较
    while (scanf("%s %s", num1, num2) == 2)
    {
        int result = compareNumbers(num1, num2);
        if (result > 0)
        {
            printf("Case %d: Bigger\n", caseNum);
        }
        else if (result < 0)
        {
            printf("Case %d: Smaller\n", caseNum);
        }
        else
        {
            printf("Case %d: Same\n", caseNum);
        }
        caseNum++;
    }

    return 0;
}
