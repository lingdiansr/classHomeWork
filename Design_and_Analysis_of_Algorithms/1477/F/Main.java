package F;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

/**
 * ClassName: F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午9:43
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            ArrayList<HashSet<Integer>> sets = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                HashSet<Integer> set = new HashSet<>();
                set.add(i+1);
                sets.add(set);
            }
            int m = sc.nextInt();
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                HashSet<Integer> aSet = null;
                HashSet<Integer> bSet = null;
                for (HashSet<Integer> set : sets) {
                    if (set.contains(a)) {
                        aSet = set;
                    }
                    if (set.contains(b)) {
                        bSet = set;
                    }
                }
                sets.remove(aSet);
                sets.remove(bSet);
                aSet.addAll(bSet);
                sets.add(aSet);
            }
            System.out.println(sets.size());
        }
    }
}
