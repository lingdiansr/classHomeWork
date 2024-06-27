package B;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int[] matrix = new int[n];
            for (int i = 0; i < n; i++) {
                matrix[i] = sc.nextInt();
            }
            int number = n - 1;
            int[][] m = new int[n][n];
            System.out.println(matrixChain(matrix, 1, number, m));
        }
        sc.close();
    }

    public static int matrixChain(int[] p, int i, int j, int[][] m) {
        if (i < p.length && j < p.length) {
            if (m[i][j] > 0) {
                return m[i][j];
            }
            if (i == j) {
                return 0;
            }
            int calNum = Integer.MAX_VALUE;
            for (int k = i; k < j; k++) {
                calNum = Math.min(calNum, matrixChain(p, i, k, m) + matrixChain(p, k + 1, j, m) + p[i - 1] * p[k] * p[j]);
            }
            m[i][j] = calNum;
            return calNum;
        } else {
            return 0;
        }
    }
}