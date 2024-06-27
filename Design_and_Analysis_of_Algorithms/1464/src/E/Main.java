package E;

import java.util.Scanner;
 
/**
 * Main
 */
public class Main {
 
    private static int[] b;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int length = sc.nextInt();
 
            int[] arr = new int[length];
            for (int i = 0; i < length; i++) {
                arr[i] = sc.nextInt();
            }
 
            int[] b = new int[length];
 
            b[0] = arr[0];
            int max = arr[0];
 
            for (int i = 1; i < length; i++) {
                if (b[i - 1] > 0) {
                    b[i] = b[i - 1] + arr[i];
                } else {
                    b[i] = arr[i];
                }
                if (b[i] > max) {
                    max = b[i];
                }
            }
            System.out.println(max);
//            for (int i : b) {
//                System.out.print(i+" ");
//            }
        }
        sc.close();
    }
 
}