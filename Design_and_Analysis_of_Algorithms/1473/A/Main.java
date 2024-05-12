package A;

import java.util.Scanner;

/**
 * ClassName: A.B.C.D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/10 - 下午9:25
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt(); // 读取序列长度
            int[] sequence = new int[n];
            for (int i = 0; i < n; i++) {
                sequence[i] = scanner.nextInt(); // 读取序列中的每个数字
            }

            int length = LongestIncreasingSubsequence(sequence);
            System.out.println(length);
        }
        scanner.close();

    }
    private static int LongestIncreasingSubsequence(int[] sequence) {
        int n = sequence.length;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1; // 初始化dp数组
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (sequence[j] < sequence[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            maxLength = Math.max(maxLength, dp[i]);
        }

        return maxLength;
    }
}
