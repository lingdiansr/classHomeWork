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

