package D;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.function.ToDoubleFunction;

/**
 * ClassName: MaIn
 * Package: PACKAGE_NAME
 * Description:
 * 部分背包
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午1:57
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Proj> projs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int p = sc.nextInt();
            int v = sc.nextInt();
            Proj e = new Proj(p, v, v * 1.0 / p);
            projs.add(e);
        }

        // 降序
        projs.sort((o1, o2) -> Double.compare(o2.e, o1.e));
//        projs.sort(Comparator.comparingDouble(o -> o.e));
        double sum = 0;
        for (int i = 0; i < n; i++) {
            Proj proj = projs.get(i);
            if (c - proj.p >= 0) {
                sum += proj.v;
                c -= proj.p;
            } else {
                sum += c * proj.e;
                break;
            }
        }
        System.out.printf("%.2f%n", sum);
    }

    public static class Proj {
        int p;
        int v;
        double e;

        public Proj(int p, int v, double e) {
            this.p = p;
            this.v = v;
            this.e = e;
        }
    }

}

