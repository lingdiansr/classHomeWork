import java.util.Scanner;
 
/**
 * Main
 */
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()){
            String str1 = sc.nextLine();
            String str2 = sc.nextLine();
            int max=0;
            int m = str1.length();
            int n = str2.length();
            int [][]dp = new int[m+1][n+1];
 
            for(int i=1; i<=m; i++) {
                for(int j=1; j<=n; j++) {
                    if (str1.charAt(i-1) == str2.charAt(j-1)) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        max=Math.max(max,dp[i][j]);
                    }
                }
            }
            System.out.println(max);
        }
        sc.close();
    }
 
 
}