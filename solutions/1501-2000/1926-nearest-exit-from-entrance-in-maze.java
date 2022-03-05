class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int n = maze.length, m = maze[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(entrance);
        boolean[][] visited = new boolean[n][m];
        int res = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int x = curr[0], y = curr[1];
                if (maze[x][y] == '+' || visited[x][y]) {
                    continue;
                }
                if (x != entrance[0] || y != entrance[1]) {
                    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) 
                        return res;
                }
                
                visited[x][y] = true;
                if (x > 0) queue.offer(new int[]{x - 1, y});
                if (x < n - 1) queue.offer(new int[]{x + 1, y});
                if (y > 0) queue.offer(new int[]{x, y - 1});
                if (y < m - 1) queue.offer(new int[]{x, y + 1});
            }
            res++;
        }
        return -1;
    }
}
