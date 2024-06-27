/*题目描述
给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。
输入
输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。
输出
对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。
样例输入 Copy
1 3
2 5
样例输出 Copy
4 28
20 152*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    long long o_sum,j_sum,x,y,temp;

    while (~scanf("%lld %lld",&x,&y))
    {
        o_sum = 0;
        j_sum = 0;
        if (x > y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        for (long long i = x; i <= y; i++)
        {
            if (i%2!=0)
            {
                j_sum += i * i * i;
            }else{
                o_sum += i * i;
            }
            
        }
        printf("%lld %lld\n", o_sum, j_sum);
    }
    
    return 0;
}