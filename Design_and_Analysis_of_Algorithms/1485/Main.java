import java.util.Scanner;
import java.util.Arrays;

public class Main {
    private static final int N = 1005;
    private static final int INF = 0x3f3f3f3f;
    private static final int MOD = 10007;
    private static int[] a = new int[N];
    private static boolean flag;
    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i - 1] = i;
        }
        do {
            flag = true;
            for (int i = 0; i < n; i++) {
                if (i == n - 1) {
                    if (!isPrime(a[i] + a[0])) {
                        flag = false;
                        break;
                    }
                } else if (!isPrime(a[i] + a[i + 1])) {
                    flag = false;
                    break;
                }
            }
            if (flag && a[0] == 1) {
                for (int i = 0; i < n; i++) {
                    System.out.print(a[i] + " ");
                }
                System.out.println();
            }
        } while (nextPermutation(a, n));
        scanner.close();
    }

    private static boolean nextPermutation(int[] a, int n) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int j = n - 1;
                while (a[j] <= a[i]) j--;
                swap(a, i, j);
                Arrays.sort(a, i + 1, n);
                return true;
            }
        }
        return false;
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}