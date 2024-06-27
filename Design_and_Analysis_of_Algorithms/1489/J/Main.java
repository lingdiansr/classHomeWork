package J;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: J
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/24 - 上午12:05
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[i] = sc.nextInt();
        }
        Arrays.sort(times);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += times[i] * (n - i);
        }
        System.out.printf("%.2f%n", sum*1.0 / n);
    }
}
