package I;

import java.util.Scanner;

/**
 * ClassName: Main
 * Package: I
 * Description:
 * 0-1背包
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午11:07
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[] weights = new int[n + 1];
        int[] beauties = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            weights[i] = sc.nextInt();
            beauties[i] = sc.nextInt();
        }

        System.out.println(zeroOneBackBag(n, c, weights, beauties));
    }


    /**
     * 0-1背包无优化
     *
     * @param n 物品数量
     * @param c 背包容量
     * @param w 代价
     * @param v 收益
     * @return 最大收益
     */
    private static int zeroOneBackBag(int n, int c, int[] w, int[] v) {
        int[][] dp = new int[n + 1][c + 1];
        int jMax = Math.min(w[n] - 1, c);
        for (int i = 0; i < jMax; i++) {
            dp[n][i] = 0;
        }
//        if (n - jMax >= 0) System.arraycopy(weights, jMax, dp[n], jMax, n - jMax);
        for (int i = w[n]; i <= c; i++) {
            dp[n][i] = v[n];
        }
        for (int i = n - 1; i >= 1; i--) {
            jMax = Math.min(w[i] - 1, c);
            for (int j = 0; j < jMax; j++) {
                dp[i][j] += dp[i + 1][j];
            }
            for (int j = w[i]; j <= c; j++) {
                dp[i][j] = Math.max(dp[i + 1][j - w[i]] + v[i], dp[i + 1][j]);
            }
        }
        return dp[1][c];
    }

}
