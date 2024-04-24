import java.util.Scanner;

/**
 * Main
 */
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String str1 = sc.nextLine();
            String str2 = sc.nextLine();
            System.out.println(Lcs(str1, str2));
        }
        sc.close();
    }

    public static int Lcs(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int[][] c = new int[m+1][n+1];
        for (int i = 0; i < m; i++) {
            c[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            c[0][i] = 0;
        }
        
        return 0;
    }
}