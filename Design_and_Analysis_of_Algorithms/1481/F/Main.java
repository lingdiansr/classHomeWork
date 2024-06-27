import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/3 - 下午8:46
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[][] G = new int[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(G[i], Integer.MAX_VALUE);
            }
            for (int i = 0; i < m; i++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                int w = scanner.nextInt();
                // 有向图权重为负
                G[x][y] = w;
                G[y][x] = w * -1;
            }
            ArrayList<Item> prim = prim(G, n);
            prim.sort((a, b) -> {
                if (a.x == b.x) {
                    return a.y - b.y;
                } else {
                    return a.x - b.x;
                }
            });
            for (Item item : prim) {
                System.out.println(item);
            }
        }
    }

    public static ArrayList<Item> prim(int[][] G, int n) {
        ArrayList<Item> items = new ArrayList<>();
        int[] closest = new int[n];
        int[] lowCost = new int[n];
        Boolean[] used = new Boolean[n];
        for (int i = 0; i < n; i++) {
            closest[i] = 0;
            used[i] = false;
            lowCost[i] = Math.abs(G[0][i]);
        }
        used[0] = true;
        for (int i = 1; i < n; i++) {
            int j = 0;
            for (int k = 0; k < n; k++) {
                if (!used[k] && lowCost[k] < lowCost[j]) {
                    j = k;
                }
            }
//            System.out.printf("%d %d %d\n", closest[j], j, lowCost[j]);
            if (G[closest[j]][j] > 0) {

                items.add(new Item(closest[j], j, lowCost[j]));
            } else {
                items.add(new Item(j, closest[j], lowCost[j]));
            }
            used[j] = true;
            for (int k = 0; k < n; k++) {
                if (!used[k] && G[j][k] < lowCost[k]) {
                    lowCost[k] = Math.abs(G[j][k]);
                    closest[k] = j;
                }
            }

        }
        return items;
    }

    public static class Item {
        int x, y, w;

        public Item(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }

        @Override
        public String toString() {
            return x + " " + y + " " + w;
        }
    }
}
