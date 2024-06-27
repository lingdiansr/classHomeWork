/*题目描述
输入一个正整数（秒钟），请将其转换成为如下格式：
时:分:秒。
输入
单组输入，输入一个正整数表示总秒数。
输出
输出转换之后的时间。
样例输入 Copy
1245
样例输出 Copy
0:20:45
*/
#include<stdio.h>

int main(int argc, const char* argv[]) {
    int second;
    int time[3];
    scanf("%d", &second);
    int i = 0;
    do
    {
        time[i++] = second % 60;
        second /= 60;
    } while (i<3);
    printf("%d:%d:%d", time[2], time[1], time[0]);

    return 0;
}