package F;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: PACKAGE_NAME
 * Description:
 * 动态规划迷宫路径代价最小
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午3:10
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] ma = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ma[j][i] = sc.nextInt();
            }
        }
        int[][] dp = new int[m][n + 2];
        int MAXVALUE = 101;
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], MAXVALUE);
        }
        System.arraycopy(ma[0], 0, dp[0], 1, n);

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j + 1] = Math.min(dp[i - 1][j + 1], Math.min(dp[i - 1][j], dp[i - 1][j + 2])) + ma[i][j];
            }
        }


        int min = MAXVALUE;
        for (int i = 1; i < n; i++) {
            min = Math.min(dp[m - 1][i], min);
        }
        System.out.println(min);
    }
}
