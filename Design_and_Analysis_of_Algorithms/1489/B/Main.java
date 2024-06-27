package B;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: PACKAGE_NAME
 * Description:
 * 普通贪心
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午12:58
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        List<Integer> jp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            jp.add(sc.nextInt());
        }
        jp.sort((o1, o2) -> o2 - o1);
        int sum = 0;
        for (int i = 0; i < m && i < n; i++) {
            sum += jp.get(i);
        }
        System.out.println(sum);
    }
}
