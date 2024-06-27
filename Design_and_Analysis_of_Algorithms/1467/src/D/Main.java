package D;

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
            int[][] s = new int[n][n];
            matrixChain(m, matrix, s);
//            System.out.println(m[1][n - 1]);

            build(s,1,n-1);
        }
        sc.close();
    }

    public static void matrixChain(int[][] matrix, int[] p, int[][] s) {
        int n = p.length - 1;
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for (int r = 2; r <= n; r++) {
            for (int i = 1; i <= n - r + 1; i++) {
                int j = i + r - 1;
                matrix[i][j] = Integer.MAX_VALUE;
                s[i][j] = i;
                for (int k = i; k < j; k++) {
//                    matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j]);
                    int u = matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (matrix[i][j] > u) {
                        matrix[i][j] = u;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
    public static void build(int[][] s,int i,int j) {
        if (i==j) return;
        build(s,i,s[i][j]);
        build(s,s[i][j]+1,j);
        System.out.println("A["+i+":"+s[i][j]+"] * A["+(s[i][j]+1)+":"+j+"]");
    }
}