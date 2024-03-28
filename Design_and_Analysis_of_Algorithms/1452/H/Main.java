import java.util.Scanner;
import java.util.Stack;

/*
题目描述
考试题目和要点：
1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。
2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。
3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。
输入
多组输入。输入一个double数。
输出
输出人民币格式。

样例输入 Copy
151121.15
样例输出 Copy
人民币拾伍万壹仟壹佰贰拾壹元壹角伍分
提示
10.56 读作人民币拾元伍角陆分
30005007 读作 三千万五千零七
30025007 读作 三千零二万五千零七
30020507 读作 三千零二万零五百零七*/
/**
 * Main
 */
public class Main {
    String digits = "零壹贰叁肆伍陆柒捌玖";
    String units = "拾佰仟万亿";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(toChinese(str));
    }

    public static String toChinese(String str) {
        String ch = "";
        int integer = Integer.parseInt(str.split(".")[0]);
        int decimal = Integer.parseInt(str.split(".")[1]);
        ch += "人民币";
        if (integer == 0) {
            ch += "零";
        } else {
            
        }
        return ch;
    }
}