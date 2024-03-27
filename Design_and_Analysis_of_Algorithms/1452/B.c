/*题目描述
使用Java或C++等语言中内置的随机函数实现随机化快速排序，在数组中随机选择一个元素作为分区的主元(Pivot)。
输入
多组样例输入，每组由一个一维整型数组组成。
输出
随机化快速排序之后的一维整型数组（升序排列）。
样例输入 Copy
6 1 8 6 5 3 4
5 12 42 2 5 8
样例输出 Copy
1 3 4 5 6 8
2 5 8 12 42*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int num[],int x,int y){
    int tmp = num[x];
    num[x] = num[y];
    num[y] = tmp;
}
int pra(int num[],int p,int q){
    srand((unsigned int)time(0));
    int x = rand() % (q - p + 1) + p;
    int i = p, j = p + 1;
    for ( ; j <= q; j++)
    {
        if (num[j]<num[x])
        {
            swap(num, ++i, j);
        }
    }
    swap(num, x, i);
    return i;
}
void qs(int num[],int p,int q){
    if (q>p)
    {
        int r = pra(num, p, q);
        qs(num, p, r - 1);
        qs(num, r + 1, q);
    }
    
}
int main(int argc, const char* argv[]) {
    int num, *numArr;
    while (~scanf("%d",&num))
    {
        int p, q;
        numArr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++)
        {
            // scanf("%d %d", &p, &q);
            scanf("%d", &numArr[i]);
            // int x = rand() % (q - p + 1) + p;
            // printf("%d", x);
        }
        qs(numArr, 0, num-1);
        for (int i = 0; i < num; i++)
        {
            printf("%d ", numArr[i]);
        }
        printf("\n");
    }

    return 0;
}
