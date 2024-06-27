package D;

import java.util.Scanner;

/**
 * ClassName: D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/12 - 下午8:42
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] value = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                value[i] = sc.nextInt();
            }
            int[] weight = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                weight[i] = sc.nextInt();
            }

            int[][] res = zeroAndOneBag(value, weight, m);
            System.out.println(res[1][m]);

            int[] ints = traceBack(value, weight, m, res);
            for (int i = 1; i < ints.length; i++) {
                System.out.print(ints[i]);
            }
            System.out.println();
        }
        sc.close();
    }

    private static int[][] zeroAndOneBag(int[] v, int[] w, int capacity) {
        int n = v.length - 1;
        int[][] res = new int[n + 1][capacity + 1];
        int max_j = Math.min(w[n] - 1, capacity);
        for (int i = 0; i < max_j; i++) {
            res[n][i] = 0;
        }
        for (int i = w[n]; i <= capacity; i++) {
            res[n][i] = v[n];
        }
        for (int i = n - 1; i >= 1; i--) {
            int max = Math.min(w[i] - 1, capacity);
            if (max + 1 >= 0) System.arraycopy(res[i + 1], 0, res[i], 0, max + 1);
            for (int j = w[i]; j <= capacity; j++) {
                res[i][j] = Math.max(res[i + 1][j], res[i + 1][j - w[i]] + v[i]);
            }
        }
        return res;
    }

    private static int[] traceBack(int[] v, int[] w, int ca, int[][] r) {
        int n = v.length - 1;
        int[] res = new int[n + 1];
        for (int i = 1; i < n; i++) {
            if (r[i][ca] == r[i + 1][ca]) {
                res[i] = 0;
            } else {
                res[i] = 1;
                ca -= w[i];
            }
        }
        res[n] = r[n][ca] > 0 ? 1 : 0;
        return res;
    }
}
