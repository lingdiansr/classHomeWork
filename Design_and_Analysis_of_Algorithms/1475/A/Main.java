package A;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] money ={25,10,5,1};
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int c = 0;
            for (int i : money) {
                while (n > 0&&n>=i) {
                    int num = Math.floorDiv(n, i);
                    if (num > 0) {
                        c += num;
                        n -= num * i;
                    }
                }
            }
            System.out.println(c);
        }

    }
}
