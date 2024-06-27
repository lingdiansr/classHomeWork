import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main
 * Package: D
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/8 - 下午9:36
 * @Version: v1.0
 */
public class Main {
    // 邻接矩阵，初始化为无穷大，表示没有连接
    private static int[][] graph;
    // 存储最短路径长度
    private static int[] shortestPathLengths;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // 顶点数
        int edges = scanner.nextInt();   // 边数

        // 初始化邻接矩阵
        graph = new int[vertices][vertices];
        shortestPathLengths = new int[vertices];

        for (int i = 0; i < graph.length; i++) {
            Arrays.fill(graph[i], Integer.MAX_VALUE);
        }


        // 读取边信息，填充邻接矩阵
        for (int i = 0; i < edges; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            int weight = scanner.nextInt();
            graph[start][end] = weight;
//            graph[end][start] = -1 * weight;
        }

        // 调用Dijkstra算法
        dijkstra();

        // 输出结果
        for (int i = 0; i < vertices; i++) {
            System.out.print(shortestPathLengths[i] + " ");
        }

    }

    // 实现Dijkstra算法
    private static void dijkstra() {
        // 标记数组，表示顶点是否已经被访问
        boolean[] visited = new boolean[graph.length];
        for (int i = 0; i < shortestPathLengths.length; i++) {
            shortestPathLengths[i] = graph[0][i];
        }
        // 从源点到自身的距离为0
        shortestPathLengths[0] = 0;
        visited[0]=true;
        for (int i = 1; i < graph.length - 1; i++) {
            // 寻找未被访问的顶点中距离最短的顶点
            int u = getMinDistanceVertex(visited);

            // 标记为已访问
            visited[u] = true;

            // 更新相邻顶点的距离
            for (int v = 0; v < graph.length; v++) {
                if (!visited[v] && graph[u][v] != Integer.MAX_VALUE
                        && shortestPathLengths[u] != Integer.MAX_VALUE
                        && (shortestPathLengths[u] + graph[u][v] < shortestPathLengths[v])) {
                    shortestPathLengths[v] = shortestPathLengths[u] + graph[u][v];
                }
            }
        }
    }

    // 寻找未被访问的顶点中距离最短的顶点
    private static int getMinDistanceVertex(boolean[] visited) {
        int minDistance = Integer.MAX_VALUE;
        int minIndex = 0;

        for (int v = 1; v < visited.length; v++) {
            if (!visited[v] && shortestPathLengths[v] < minDistance) {
                minDistance = shortestPathLengths[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
}
