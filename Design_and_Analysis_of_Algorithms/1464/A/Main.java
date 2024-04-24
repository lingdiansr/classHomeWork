import java.util.Scanner;

/**
 * Main
 */
public class Main {
    static String str1;
    static String str2;
    static int m;
    static int n;
    static int[][] c = new int[m + 1][n + 1];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            str1 = sc.nextLine();
            str2 = sc.nextLine();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = 0;
                }
            }
            System.out.println(Lcs(str1, str2, str1.length() - 1, str2.length() - 1));
        }
        sc.close();
    }

    public static int Lcs(String s1, String s2, int x, int y) {

        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {

        //     }
        // }
        if (c[x][y] == 0) {
            if (s1.charAt(x) == s2.charAt(y)) {
                c[x][y] = Lcs(s1, s2, x - 1, y - 1) + 1;
            } else {
                c[x][y] = Math.max(Lcs(s1, s2, x - 1, y), Lcs(s1, s2, x, y - 1));
            }
        }
        return c[x][y];
    }
}