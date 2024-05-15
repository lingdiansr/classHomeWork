package F;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/15 - 下午11:26
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            pro[] pros = new pro[n];
            for (int i = 0; i < n; i++) {
                pros[i] = new pro(sc.nextInt(), sc.nextInt());
            }
            Arrays.sort(pros, (o1, o2) -> {
                return Double.compare(o2.per, o1.per);
            });
            double total = 0;

            for (pro pro : pros) {
                if (m < pro.prices) {
                    total += m * pro.per;
                    break;
                } else if (m >= pro.prices) {
                    total += pro.values;
                    m -= pro.prices;
                }
            }
            System.out.printf("%.2f\n", total);
            System.out.println();
        }
        sc.close();
    }

    static class pro {
        int prices;
        int values;
        double per;

        public pro(int prices, int values) {
            this.prices = prices;
            this.values = values;
            this.per = (double) values / (double) prices;
        }
    }
}
