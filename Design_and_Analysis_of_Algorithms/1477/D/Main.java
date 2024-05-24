package D;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午9:25
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            Integer[] integers = new Integer[n];
            for (int i = 0; i < n; i++) {
                integers[i] = sc.nextInt();
            }
            Arrays.sort(integers);
            int sum=0;
            for (int i = 0; i < n-1; i++) {
                sum+=integers[i]*(n-i-1);
            }
            System.out.printf("%.2f",(double)sum/n);
            System.out.println();
        }
    }
}
