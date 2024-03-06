
/*
 * 题目描述
 * 你是学生会体育部长，负责组织一年一度的校篮球比赛。马上就要决赛了，你希望吸引更多的 人来看比赛，
 * 因此打算更新一下设备，用一个超大的 LED屏幕来显示比分。当然，电也不是 不要钱的，所以你决定先分析一下往年的比赛，
 * 估计一下大概要耗多少电。
 * 
 * 如上图，每个数字由 7条线段组成，每条亮着的线段每秒钟耗电量为 1个单位。线段不亮的时 候不耗电。为了省电，
 * 比分不显示前导 0（不过 0分的时候要显示数字 0）。
 * 你的 LED显示屏共包含 6个数字，即双方的比分各有 3 位数。
 * 
 * 输入
 * 输入包含不超过 100组数据。每组数据第一行为"START hh:mm:ss"，表示比赛开始时刻为 hh:mm:ss。
 * 最后一行为"END hh:mm:ss"，即比赛结束时刻。二者之间至少会有一个 SCORE信
 * 息，格式为"SCORE hh:mm:ss team score"，
 * 其中 team要么是"home"（主场）要么是"guest"（客 场）, score表示得分，为 1,2或者 3。这些信息保证按照时间从早到晚的顺序排列，
 * 且任意两 条 SCORE信息的时刻均不相同。比赛开始时间不会早于 9:00，结束时间不会晚于同一天的 21:00。
 * 注意，如果比赛开始时间为 09:00:00，结束时间为 09:00:01，比赛长度为 1秒钟，而不 是 2秒钟。
 * 
 * 输出
 * 对于每组数据，输出测试点编号和总耗电量。
 * 
 * 样例输入 Copy
 * START 09:00:00
 * SCORE 09:01:05 home 2
 * SCORE 09:10:07 guest 3
 * END 09:15:00
 * START 09:00:00
 * SCORE 10:00:00 home 1
 * SCORE 11:00:00 home 1
 * SCORE 12:00:00 home 1
 * SCORE 13:00:00 home 1
 * SCORE 14:00:00 home 1
 * SCORE 15:00:00 home 1
 * SCORE 16:00:00 home 1
 * SCORE 17:00:00 home 1
 * SCORE 18:00:00 home 1
 * SCORE 19:00:00 home 1
 * SCORE 20:00:00 home 1
 * END 21:00:00
 * 样例输出 Copy
 * Case 1: 9672
 * Case 2: 478800
 */
package G_超大型_LED_显示屏;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

/**
 * G_超大型 LED 显示屏
 */
public class Main {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        long power = 0, startTime, nowTime;
        int score, homeScore, guestScore;
        int count = 0;
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
        while (sc.hasNextLine()) {
            String[] timeStrings = new String[4];
            timeStrings = sc.nextLine().split(" ");
            power = 0;
            score = homeScore = guestScore = 0;
            startTime = sdf.parse(timeStrings[1]).getTime() / 1000;
            do {
                timeStrings = sc.nextLine().split(" ");
                nowTime = sdf.parse(timeStrings[1]).getTime() / 1000;
                power += (nowTime - startTime) * (getNum(homeScore) + getNum(guestScore));
                startTime = nowTime;
                if (timeStrings[0].equals("END")) {
                    break;
                }
                if (timeStrings[2].equals("home")) {
                    homeScore += Integer.parseInt(timeStrings[3]);
                } else {
                    guestScore += Integer.parseInt(timeStrings[3]);
                }
                // timeStrings = sc.nextLine().split(" ");
            } while (!timeStrings[0].equals("END"));
            // timeStrings = sc.nextLine().split(" ");
            // nowTime = sdf.parse(timeStrings[1]).getTime() / 1000;
            // power += (nowTime - startTime) * (getNum(homeScore) + getNum(guestScore));
            System.out.println("Case " + (++count) + ": " + power);
        }
        sc.close();
    }

    private static int getNum(int score) {
        int[] num = new int[] { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
        int sum = 0;
        if (score == 0)
            return 6;
        while (score > 0) {

            sum += num[score % 10];
            score /= 10;
        }
        // do {
        // sum += num[score[0] % 10];
        // } while ((score[0] /= 10;) != 0);
        // do {
        // sum += num[score[1] % 10];
        // } while ((score[1] /= 10) != 0);
        return sum;
    }
}
