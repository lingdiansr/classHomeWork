package A;

import java.util.Scanner;

/**
 * ClassName: A.B.C.D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/30 - 下午8:22
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            n++;
            for (int i = 1; i <= n; i++) {
                print(n, i);
            }
            for (int i = n-1; i >= 1; i--) {
                print(n, i);
            }
            System.out.println();
        }
    }

    private static void print(int n, int i) {
        for (int j = 0; j < n-i; j++) {
            System.out.print(" ");
        }
        for (int j = 0; j < i; j++) {
            System.out.print("* ");
        }
        System.out.println();
    }
}
