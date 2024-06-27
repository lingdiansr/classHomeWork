package B;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] money = {1, 4, 9, 16, 25, 100};

        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int[] dp = new int[n + 1];
            for (int m : money) {
                for (int i = m; i <= n; i++) {
                    if (dp[i] != 0) {
                        dp[i] = Math.min(dp[i], dp[i - m] + 1);
                    } else {
                        dp[i] = dp[i - m] + 1;
                    }
                }
            }


            System.out.println(dp[n]);
        }
    }
}
