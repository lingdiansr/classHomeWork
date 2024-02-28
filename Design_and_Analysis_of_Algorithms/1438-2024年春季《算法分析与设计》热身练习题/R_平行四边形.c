/*题目描述
Kimi想用“*”号构成一个平行四边形并在屏幕上输出。
当输入一个大于等于2的正整数N时，屏幕上将显示一个由N*N个“*”组成的平行四边形。
例如：输入3，输出如下平行四边形。
  ***
 ***
***
输入
输入一个正整数N，1<N<=100。
输出
输出一个N行，每行N个“*”组成的平行四边形。
样例输入 Copy
3
样例输出 Copy
  ***
 ***
***
*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = n; i>0; i--)
    {
        for (int j = 0; j < i-1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}