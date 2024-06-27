package F;

import java.util.Scanner;

/**
 * ClassName: F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/12 - 下午9:23
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] value = new int[n + 1];
            int[] weight = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                weight[i] = sc.nextInt();
            }
            for (int i = 1; i <= n; i++) {
                value[i] = sc.nextInt();
            }
            int[][] res = zeroAndOneBag(value, weight, m);
            System.out.println(res[1][m]);

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

}
