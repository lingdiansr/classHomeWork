/*题目描述
请编写一个程序，输入包含n（n<=10000）个整数的数列S以及包含q个(q<=500)不重复整数的数列T，输出既包含于T也包含于S的整数的个数C。S、T中的元素均大于0且小于109，T的元素不重复。
输入
多组输入。
每一组输入的第一行输入n，第二行输入代表S的n个整数，第三行输入q，第四行输入代表T的q个整数。
输出
用1行输出C。
样例输入 Copy
5
1 2 3 4 5
3
3 4 1
样例输出 Copy
3*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int n, q, count ;
    int *s, *t;
    while (~scanf("%d", &n))
    {
        count = 0;
        s = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
        }
        scanf("%d", &q);
        t = (int *)malloc(sizeof(int) * q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &t[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                if (s[i] == t[j])
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    
    return 0;
}