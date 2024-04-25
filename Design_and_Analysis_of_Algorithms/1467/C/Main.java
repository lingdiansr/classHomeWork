package C;

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int[] matrix = new int[n];
            for (int i = 0; i < n; i++) {
                matrix[i] = sc.nextInt();
            }
            int[][] m = new int[n][n];
            matrixChain(m, matrix);
            System.out.println(m[1][n-1]);
        }
        sc.close();
    }

    public static void matrixChain(int[][] matrix, int[] p) {
        int n = p.length - 1;
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for (int r = 2; r <= n; r++) {
            for (int i = 1; i <= n - r + 1; i++) {
                int j = i + r - 1;
//                matrix[i][j]=matrix[i+1][j]+p[i-1]*p[i]*p[j];
                matrix[i][j]=Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j]);
                }
            }
        }
    }
}