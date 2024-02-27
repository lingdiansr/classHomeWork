/*题目描述
XP最近发现一个很好玩的问题。现在有N盏电灯，序号为1到N，最开始的时候所有电灯都是关闭的。XP有一群同学，序号是（1~K）,这些调皮的同学会去按电灯的开关，每个同学按开关符合一种规律。序号为1的同学会按下序号是1的倍数的灯的开关，序号是2的同学会按下序号是2的倍数的灯的开关（将关的灯打开，开的灯关闭）。现在XP有K位同学，每位同学都去操作一次，问最后有多少盏灯是亮着的？
输入
每行输入两个整数，N，K（K<=N<=1000）
输出
每行输入一个整数，表示打开电灯的数量。
样例输入 Copy
2 2
10 10
样例输出 Copy
1
3*/
#include <stdio.h>

int main()
{
    int N, K;
    while (~scanf("%d %d", &N, &K))
    {
        int lights[N + 1];
        for (int i = 1; i <= N; i++)
        {
            lights[i] = 0;
        }

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j % i == 0)
                {
                    lights[j] = !lights[j];
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            if (lights[i] == 1)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
