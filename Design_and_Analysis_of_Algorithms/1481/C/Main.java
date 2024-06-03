package C;

import java.util.*;

/**
 * ClassName: C.D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/1 - 下午4:30
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
                set.add(i);
                sets.add(set);
            }
            int m = sc.nextInt();
            sc.nextLine();
            for (int i = 0; i < m; i++) {
                String[] strings = sc.nextLine().split(" ");
                strings=Arrays.copyOfRange(strings,1,strings.length);
                int[] array = Arrays.stream(strings).mapToInt(Integer::parseInt).toArray();
                Iterator<HashSet<Integer>> iterator = sets.iterator();
                HashSet<Integer> aSet = null;
                while (iterator.hasNext()) {
                    HashSet<Integer> next = iterator.next();
                    if (next.contains(array[0])) {
                        aSet = next;
                        break;
                    }
                }
                for (int j = 1; j < array.length; j++) {
                    HashSet<Integer> bSet = null;
                    Iterator<HashSet<Integer>> it = sets.iterator();
                    while (it.hasNext()) {
                        HashSet<Integer> next = it.next();
                        if (next.contains(array[j])) {
                            bSet = next;
                            break;
                        }
                    }

                    sets.remove(aSet);
                    sets.remove(bSet);
                    if (aSet != null) {
                        if (bSet != null) {
                            aSet.addAll(bSet);
                        }
                    }
                    sets.add(aSet);
                }
            }
            for (HashSet<Integer> set : sets) {
                if (set.contains(0)) {
                    System.out.println(set.size());
                    break;
                }
            }
        }
    }
}
