package S_临时换人;

/*题目描述
因为某些原因，Jack和Rose没有办法参加毕业演出，他们两个的工作任务都将由劳模Tom来代替。
现在需要更新演职人员名单，将所有的Jack和Rose替换成Tom。
请你编写一段程序实现人员替换功能。
输入
单组输入。
输入一个字符串（可能有空格,字符串长度<=1e5），包含若干Jack和Rose。
输出
输出替换之后的字符串。
样例输入 Copy
Cameraman: Jack, Lighting engineer: Rose.
样例输出 Copy
Cameraman: Tom, Lighting engineer: Tom.
*/
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String s;
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();
        s = s.replaceAll("Jack", "Tom");
        s = s.replaceAll("Rose", "Tom");
        System.out.println(s);
        scanner.close();
    }
}
