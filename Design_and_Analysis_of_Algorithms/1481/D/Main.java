import java.util.*;

/**
 * ClassName: D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/3 - 下午7:37
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
            for (int i = 0; i < n; i++) {
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
            //升序
            edges.sort(Comparator.comparingInt(e -> e.w));
            int sum = 0;
            for (Edge edge : edges) {
                if (!extracted(sets, edge.x, edge.y)) {
                    sum += edge.w;
                }
            }
            System.out.println(sum);
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

        @Override
        public String toString() {
            return "Edge{" +
                    "x=" + x +
                    ", y=" + y +
                    ", w=" + w +
                    '}';
        }
    }
}
