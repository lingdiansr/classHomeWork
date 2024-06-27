#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// 函数用于格式化单行数据
void formatLine(const char *line)
{
    char filename[8];
    char category[2];
    double confidence;
    int x1, y1, x2, y2;

    // 提取各个字段的数据
    strncpy(filename, line, 11);
    filename[11] = '\0';
    sscanf(line + 12, "%1s", category);
    sscanf(line + 14, "%lf", confidence);
    sscanf(line + 26, "%d", &x1);
    sscanf(line + 31, "%d", &y1);
    sscanf(line + 36, "%d", &x2);
    sscanf(line + 41, "%d", &y2);

    // 打印格式化后的数据
    printf("%-7s %1d %.9lf %4d %4d %4d %4d\n",
           filename,
           category[0] - '0', // 转换为数字
           confidence,
           x1,
           y1,
           x2,
           y2);
}

int main()
{
    char data[MAX_LINE_LENGTH];

    // 假设数据是按行存储的，这里只是一个示例
    const char *lines[] = {
        "test0.jpg 2 0.999334872 243 59 491 319",
        "test1.jpg 3 0.999944568 471 290 1440 1072",
        // ... 更多行数据
    };

    int numLines = sizeof(lines) / sizeof(lines[0]);

    for (int i = 0; i < numLines; ++i)
    {
        formatLine(lines[i]);
    }

    return 0;
}