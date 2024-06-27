package E;

import java.util.Scanner;

/**
 * ClassName: E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/15 - 下午11:02
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int[] arr = new int[k + 1];
            for (int i = 0; i < k + 1; i++) {
                arr[i] = scanner.nextInt();
            }
            int car = car(n, k, arr);
            if (car != -1) {
                System.out.println(car);
            }
        }
    }

    public static int car(int n, int k, int[] arr) {
        int count = 0;
        int nn = n;
        for (int i : arr) {
            if (i > n) {
                System.out.println("No Solution");
                return -1;
            }
            if (nn < i) {
                count++;
                nn = n;
            }
            nn -= i;
        }
        return count;
    }
}
