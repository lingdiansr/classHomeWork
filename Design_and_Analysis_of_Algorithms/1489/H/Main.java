package H;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: H
 * Description:
 * 不知道，大概是贪心
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午5:19
 * @Version: v1.0
 */
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        ArrayList<Integer> va = new ArrayList<>();
        ArrayList<Integer> children = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            va.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            children.add(scanner.nextInt());
        }
        va.sort(Integer::compareTo);
        children.sort(Integer::compareTo);
        int j = 0;
        out:for (int i : va) {
            if (i<children.get(0)) {
                continue;
            }
            while (children.get(j) > i) {
                j++;
                if (j == n) {
                    j=0;
                    continue out;
                }
            }
            children.remove(j);
        }
        System.out.println(n - children.size());

//        int j=0;
//        int sum=0;
//        for (int i = 0; i < children.size(); i++) {
//            while (j< m &&va.get(j)<children.get(i)){
//                j++;
//            }
//            if (j==m) {
//                break;
//            }
//            sum++;
//            j++;
//        }
//        System.out.println(sum);
    }
}
