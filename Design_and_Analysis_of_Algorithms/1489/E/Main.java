package E;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: PACKAGE_NAME
 * Description:
 * 普通贪心
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午2:57
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] kimi = new Integer[n];
        Integer[] sunny = new Integer[n];
        int[] ints = new int[n];
        for (int i = 0; i < n; i++) {
            kimi[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            sunny[i] = sc.nextInt();
        }
        Arrays.sort(kimi, Integer::compareTo);
        Arrays.sort(sunny, Comparator.reverseOrder());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum+=kimi[i]*sunny[i];
        }
        System.out.println(sum);
    }
}
