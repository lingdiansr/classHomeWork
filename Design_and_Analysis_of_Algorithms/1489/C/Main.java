package C;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: PACKAGE_NAME
 * Description:
 * 最长递增子序列变形
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午1:10
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(n - LDS(nums));
    }

    public static int LDS(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            int maxLen = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j] && dp[j] + 1 > maxLen) {
                    maxLen = dp[j];
                }
            }
            dp[i] = maxLen + 1;
        }
        return Arrays.stream(dp).max().getAsInt();
    }
}
