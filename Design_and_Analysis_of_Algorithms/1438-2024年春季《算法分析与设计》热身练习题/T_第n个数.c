/*题目描述
自从学了素数以后，明明喜欢上了数字2、3和5。当然，如果一个数字里面只出现2、3和5这三个数字，他也一样喜欢，例如222、2355、223355。
现在他希望你能够帮他编写一个程序，快速计算出由2、3、5这三个数字组成的由小到大的第n个数，当然也包括2、3和5。
输入
每组输入数据占1行，每行输入一个正整数n。（n<=1000）
输出
每组输出数据占1行，即满足要求的第n个数。
样例输入 Copy
3
样例输出 Copy
5*/
#include<stdio.h>
#include<stdbool.h>
bool isFit(int n) {
    bool flag=true;
    int t;
    do
    {
        t = n % 10;
        if (!(t==2||t==3||t==5))
        {
            flag = false;
            break;
        }
        
    } while (n/=10);
    return flag;
}
int main(int argc, const char* argv[]) {
    int input;
    int num[1000];
    int count = 2;
    num[0] = 2;
    num[1] = 3;
    num[2] = 5;
    while (count<1000)
    {
        int number = num[count]+1;
        while (!isFit(number))
        {
            number++;
        }
        num[++count] = number;
    }
    // for (int i = 0; i < 1000; i++)
    // {
    //     if ((i+1)%5==0)
    //     {
    //         printf("\n");
    //     }
        
    //     printf("%d ", num[i]);
    // }
    while (~scanf("%d",&input))
    {
        printf("%d\n", num[input -1]);
    }
    

    return 0;
}