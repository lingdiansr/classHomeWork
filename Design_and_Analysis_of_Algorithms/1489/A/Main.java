package A;

import java.util.Scanner;

/**
 * ClassName: A.Main
 * Package: PACKAGE_NAME
 * Description:
 * 递归
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 上午11:29
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.printf("%.6f", Math.floor(0.0000005*1e7)*1e-7);

    }

    public static double fun(int n) {
        if (n <= 1) {
            return 1 / 2.0;
        } else {
            return fun(n - 1) + 1.0 / (n * (n + 1));
        }
//        return n * 0.5;
    }
}
