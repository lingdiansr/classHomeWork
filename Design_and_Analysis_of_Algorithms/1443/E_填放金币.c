/*题目描述
X星人在一艘海底沉船上发现了很多很多很多金币，可爱的X星人决定用这些金币来玩一个填格子的游戏。
其规则如下：第1个格子放2枚金币，第2个格子放5枚金币，第3个格子放10枚金币，第4个格子放17枚金币，第5个格子放26枚金币，以此类推。
请问放到第n个格子时一共放了多少枚金币？
请用递归编写一个程序统计第1个格子到第n个格子的总金币数量。
【友情提醒：请使用递归来实现】
输入
多组输入。每组一个正整数n，表示最后一个格子的编号。（n<=100）
输出
对于每一组输入，输出从第1个格子到第n个格子的总金币数。
样例输入 Copy
1
3
样例输出 Copy
2
17*/
#include <stdio.h>
int num(int n){
    if (n==1)
    {
        return 2;
    }else
    {
        return num(n - 1) + 2 * n - 1;
    }
}
int recursion(int n)
{
    if (n==1)
    {
        return 2;
    }else
    {
        return recursion(n - 1) + num(n);
    }
    
    
}
int main(int argc, const char *argv[])
{
    int n;
    while (~scanf("%d",&n))
    {
        printf("%d\n", recursion(n));
    }
    
    return 0;
}