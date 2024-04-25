package F;

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = Integer.parseInt(sc.nextLine());
            if (n == 0) break;
            String x1 = sc.nextLine();
            String x2 = sc.nextLine();
            x1 = x1.replaceAll(" ", "");
            x2 = x2.replaceAll(" ", "");
            int common = longestCommonSubsequence(x1, x2);
            System.out.println((common / (double) n - 0.5) < 1e-6 ? "Yes" : "No");
        }
        sc.close();
    }

    public static int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}