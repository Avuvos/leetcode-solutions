class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        
        if (queue.size() == 0 || queue.size() == m*n) return -1;
        
        int dist = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int [] curr = queue.poll();
                int x = curr[0], y = curr[1];
                if (x > 0) {
                    if (!visited[x - 1][y]) queue.offer(new int[] {x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (x < n - 1) {
                    if (!visited[x + 1][y]) queue.offer(new int[] {x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (y > 0) {
                    if (!visited[x][y - 1]) queue.offer(new int[] {x, y - 1});
                    visited[x][y - 1] = true;
                }
                    
                if (y < m - 1) {
                    if (!visited[x][y + 1]) queue.offer(new int[] {x, y + 1});
                    visited[x][y + 1] = true;
                }
            }
            dist++;
        }
        return dist - 1;
    }
}
