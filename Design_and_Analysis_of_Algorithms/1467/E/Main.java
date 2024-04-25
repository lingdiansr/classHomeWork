package E;

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
            int[][] m = new int[n+1][n+1];
            int[][] sum = new int[n+1][n+1];
            calSum(sum, matrix);
            matrixChain(m, matrix,sum);
            System.out.println(m[1][n]);

        }
        sc.close();
    }

    private static void calSum(int[][] sum, int[] p) {

        int n = p.length;
        for (int i = 1; i <= n; i++) {
            sum[i][i] = p[i-1];
        }
        for (int r = 2; r<= n; r++) {
            for (int i = 1; i <= n-r+1; i++) {
                int j = i+r-1;
                sum[i][j]=sum[i][j-1]+p[j-1];
            }
        }
    }

    public static void matrixChain(int[][] matrix, int[] p, int[][] sum) {
        int n = p.length ;
        for (int i = 0; i < n; i++) {
//            Arrays.fill(matrix[i], Integer.MAX_VALUE);
            matrix[i][i]=0;
        }
        for (int r = 2; r <= n; r++) {
            for (int i = 1; i <= n - r + 1; i++) {
                int j = i + r - 1;
                matrix[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {

                    matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] +sum[i][j]);
                }
            }
        }
    }

}