import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] s = new int[4];
            int cnt = 0;
            while (n > 0) {
                s[cnt++] = n % 10;
                n /= 10;
            }
            System.out.printf("Case %d: %d\n", i + 1, solve(s));
        }
        scanner.close();
    }

    private static int solve(int[] s) {
        int ans = 0;
        int ai = 0;
        int[] a = new int[98]; // 从31*31到99*99共有98个数
        for (int i = 31; i < 100; i++) {
            a[ai++] = i * i;
        }

        for (int i = 0; i < 4; i++) {
            int tp = 1;
            for (int j = i; j > 0; j--) {
                tp *= 10;
            }
            int num = 0;
            for (int j = 0; j <= 9; j++) {
                if (s[i] == j || (i == 3 && j == 0)) {
                    continue;
                }
                num = num * 10 + j;
                if (judge(num + s[i] * tp, a, ai)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private static boolean judge(int x, int[] a, int ai) {
        for (int j = 0; j < ai; j++) {
            if (x == a[j]) {
                return true;
            }
        }
        return false;
    }
}