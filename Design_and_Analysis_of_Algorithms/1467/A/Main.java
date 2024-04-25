package A;

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];
            int[] max = new int[n];
            int[] min = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            for (int r = 1; r <= n; r++) {
                max[r - 1] = Integer.MIN_VALUE;
                min[r - 1] = Integer.MAX_VALUE;
                for (int i = 0; i < n - r + 1; i++) {
                    int j = i + r - 1;
                    max[r - 1] = Math.max(max[r - 1], arr[i][j]);
                    min[r - 1] = Math.min(min[r - 1], arr[i][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.println("L" + (i + 1) + "=" + max[i] + ", S" + (i + 1) + "=" + min[i]);
            }
        }
        sc.close();
    }
}