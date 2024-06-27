import java.util.*;

/**
 * ClassName: E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/3 - 下午8:37
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            List<Edge> edges = new ArrayList<Edge>();
            ArrayList<HashSet<Integer>> sets = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                HashSet<Integer> s = new HashSet<>();
                s.add(i);
                sets.add(s);
            }
            for (int i = 0; i < m; i++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                int w = scanner.nextInt();
                edges.add(new Edge(x, y, w));
            }
//            edges.sort(Comparator.comparingInt(e -> e.w));
            //降序
            edges.sort((e1, e2) -> e2.w - e1.w);

            // w<1e9
            long sum = 0;
            for (Edge edge : edges) {
                if (!extracted(sets, edge.x, edge.y)) {
                    sum += edge.w;
                }
            }
            if (sets.size()==1) {
                System.out.println(sum);
            }else {
                System.out.println("No solution.");
            }
        }
    }

    private static boolean extracted(ArrayList<HashSet<Integer>> sets, int a, int b) {
        HashSet<Integer> aSet = null;
        HashSet<Integer> bSet = null;
        Iterator<HashSet<Integer>> iterator = sets.iterator();
        while (iterator.hasNext()) {
            HashSet<Integer> next = iterator.next();
            if (next.contains(a)) {
                aSet = next;
            }
            if (next.contains(b)) {
                bSet = next;
            }
        }
        sets.remove(aSet);
        sets.remove(bSet);
        aSet.addAll(bSet);
        sets.add(aSet);
        return aSet.equals(bSet);
    }

    public static class Edge {
        int x;
        int y;
        int w;

        public Edge(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }
    }
}
