/*
题目描述
热爱数学的X星人又发现了一个有趣的游戏，游戏名叫做：1的个数。
具体游戏规则为：给定一个十进制正整数，计算对应的二进制整数中有多少个1。
输入
多组输入。
第一行输入一个整数T（1<=T<=100)，表示总共有T组数据。
接下来T行，每行一个十进制正整数n，其中1<=n<=1e^9。
输出
对于每一组输入，输出十进制正整数对应的二进制整数中包含的1的个数。
样例输入 Copy
3
1
9
12
样例输出 Copy
1
2
2*/
#include<stdio.h>
#include<math.h>
int main(int argc, const char* argv[]) {
    int n,num,count;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        count = 0;
        do
        {
            if (num%2==1)
            {
                count++;
            }
                        
            num = num / 2;
        } while (num > 0);
        printf("%d\n", count);
    }

    return 0;
}