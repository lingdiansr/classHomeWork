import java.util.Scanner;

public class Main {

    // 定义八个方向
    private static final int[] dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    private static final int[] dy = {0, 0, -1, 1, -1, 1, -1, 1};

    // 深度优先搜索函数
    private static void dfs(char[][] grid, boolean[][] visited, int x, int y) {
        // 标记当前位置为已访问
        visited[x][y] = true;

        // 遍历八个方向
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 判断新位置是否在边界内且为'@'且未被访问
            if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && grid[nx][ny] == '@' && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            scanner.nextLine();  // 读取换行符

            char[][] grid = new char[m][n];
            boolean[][] visited = new boolean[m][n];

            // 读取字符矩阵
            for (int i = 0; i < m; i++) {
                grid[i] = scanner.nextLine().toCharArray();
            }

            int count = 0;

            // 遍历整个矩阵
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // 如果发现一个未被访问的'@'，则进行深度优先搜索
                    if (grid[i][j] == '@' && !visited[i][j]) {
                        dfs(grid, visited, i, j);
                        count++;  // 连通块计数加1
                    }
                }
            }

            // 输出结果
            System.out.println(count);
        }

        scanner.close();
    }
}
