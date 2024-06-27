package C;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: C
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/12 - 下午8:37
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
            System.out.println(n-length);
        }
        scanner.close();
    }
    private static int LongestIncreasingSubsequence(int[] sequence) {
        int n = sequence.length;
        int[] dp = new int[n];
        // 初始化dp数组
        Arrays.fill(dp, 1);

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
