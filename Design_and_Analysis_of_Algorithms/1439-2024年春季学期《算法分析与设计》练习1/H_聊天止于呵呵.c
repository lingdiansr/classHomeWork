/*题目描述
（现代版）俗话说：流言止于智者，聊天止于呵呵。输入一段聊天记录，你的任务是数一数有 多少段对话“止于呵呵”，即对话的最后一句话包含单词 hehe或者它的变形。
具体来说，我们首先提取出对话的最后一句话，把所有非字母的字符替换成空格，把所有字符 替换成小写，然后导出一个单词列表（由空格隔开），只要列表中的任何一个单词是 hehe，这 段对话就算作“止于呵呵”。比如，"Hi! Are you OK?" 会变成四个单词：hi, are, you, ok。注 意，单词列表可以是空的（比如，这句话是："?!?!!"）
有些人喜欢使用 hehe的变形，这些变形也应被视为“呵呵”。为了简单起见，本题只考虑由 n(n>1)个 he连接而成的单词，比如 hehehe或者 hehehehe。注意，以 hehe为连续子串的其他单 词不应视为“呵呵”，比如 hehee，或者 ehehe。
每两个不同人之间的所有对话算作“一段对话”。

输入
输入仅包含一组数据，每行是一句对话，格式为：

人名 1->人名 2: 一句话.

每行最多包含 1000个字符，最多 100行。

输出
输出“止于呵呵”的对话段落所占的百分比，四舍五入到最近的整数。输入数据保证答案不会 同时和两个整数最近。

样例输入 Copy
A->B: Hello!
A->C: Hi!
B->A: Hehe
B->D: Hei!
D->B: How are you?
A->C: Hi???
A->C: Are you there?
B->D: Hehehei!
D->B: What does hehehei mean?
F->E: I want to hehehehehe yah.
样例输出 Copy
50%
提示
样例解释
A 和 B 之间的最后一句话是"Hehe".
A 和 C 之间的最后一句话是"Are you there?".
B 和 D 之间的最后一句话是"What does hehehei mean?".
E 和 F 之间的最后一句话是"I want to hehehehehe yah". 最后第一段和最后一段话是“止于呵呵”的(注意最后一段对话是以呵呵的变种结束),因此 比例是 50%。

*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool ishehe(char word[]){
    bool flag = true;
    for (int i = 0; word[i]!='\0'; i+=2)
    {
        if (word[i] != 'h'|| word[i+1]!='e')
        {
            flag = false;
        }
        
    }
    return flag;
}
char *chuli(char msg[])
{
    char *rez;
    int i;
    for (i = 0; msg[i] != '\0'; i++)
    {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            rez[i] = msg[i] + 32;
        }
        else if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            rez[i] = msg[i];
        }
        else
        {
            rez[i] = ' ';
        }
    }
    rez[i] = '\0';
    return rez;
}
bool havehehe(char msg[]){
    char *massage = chuli(msg);
    bool flag = false;
    int wordStart = 0, wordEnd = 0;
    for (int i = 0; massage[i+1]!='\0'; i++)
    {
        if (massage[i]==' ')
        {
            wordEnd = i - 1;
            if ((wordEnd - wordStart + 1) % 2 == 0)
            {
                char *word;
                strncpy(word, massage + wordStart, wordEnd - wordStart + 1);
                flag = ishehe(word);
            }
            wordStart = i + 1;
        }               
    }
}
int main(int argc, const char* argv[]) {
    char per1,per2,tmp;
    int dia[26][26];
    char massage[101][1001];
    int i = 0;
    double totalCount = 0, heheCount = 0,rate;
    while (~scanf("%c",&per1))
    {
        if (per1=='\n')
        {
            break;
        }
        
        scanf("->%c: ", &per2);
        if (per2 < per1)
        {
            tmp = per1;
            per1 = per2;
            per2 = tmp;
        }
        dia[per1 - 65][per2 - 65] = i;
        gets(massage[i]);
        i++;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i!=j)
            {
                if (dia[i][j]>0)
                {
                    totalCount++;
                    if (ishehe(massage[dia[i][j]]))
                    {
                        heheCount++;
                    }
                    
                }
                
            }
            
        }
        
    }
    rate = heheCount / totalCount;
    printf("%.0lf%%", rate*100);
    // if (ishehe("hehhhe"))
    // {
    //     printf("true");
    // }else{
    //     printf("false");
    // }
    
    return 0;
}

