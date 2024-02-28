/*题目描述
请编写一个程序，统计一个二维整型数组中出现的奇数的个数，已知该数组中包含的整数全为正整数。
输入
单组输入。
第1行输入两个正整数M和N，分别表示二维整型数组的行数和列数，M和N均不超过100，且二者之间用英文空格隔开。
接下来M行，每行输入N个正整数，两两之间用英文空格隔开，每个整数均不超过1000。
输出
输出该二维整型数组中包含的奇数的个数。
样例输入 Copy
3 3
1 2 3
2 3 4
4 6 9
样例输出 Copy
4*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    int count=0,x,y,num;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < x*y; i++)
    {
        scanf("%d",&num);
        if (num%2!=0)
        {
            count++;
        }
        
    }
    printf("%d\n", count);
    return 0;
}