package D;

import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    static class Cake {
        double num;
        double sale;
        double pns;

        Cake(double num, double sale) {
            this.num = num;
            this.sale = sale;
            this.pns = sale / num;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            double s = scanner.nextDouble();
            Cake[] moon = new Cake[n];
            for (int i = 0; i < n; i++) {
                moon[i] = new Cake(scanner.nextDouble(), 0.0);
            }
            for (int i = 0; i < n; i++) {
                moon[i].sale = scanner.nextDouble();
                moon[i].pns = moon[i].sale / moon[i].num;
            }

            Arrays.sort(moon, new Comparator<Cake>() {
                @Override
                public int compare(Cake a, Cake b) {
                    return Double.compare((b.pns - a.pns), 0);
                }
            });

            double total = 0;
            for (int j = 0; j < n; j++) {
                if (s < moon[j].num) {
                    total += s * moon[j].pns;
                    break;
                } else if (s >= moon[j].num) {
                    total += moon[j].sale;
                    s -= moon[j].num;
                }
            }

            System.out.printf("%.2f", total);
            System.out.println();
        }
        scanner.close();

    }
}