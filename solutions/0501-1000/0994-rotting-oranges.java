class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new int[]{i, j});
                }
            }
        }
        int mins = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            boolean reach = false;
            for (int i=0; i<size; i++) {
                int [] curr = q.poll();
                int x = curr[0], y = curr[1];
                if (x > 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    q.offer(new int[]{x-1, y});
                    reach = true;
                }
                if (x < grid.length-1 && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    q.offer(new int []{x+1, y});
                    reach = true;
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    q.offer(new int[]{x, y-1});
                    reach = true;
                }
                if (y < grid[0].length-1 && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    q.offer(new int[]{x, y+1});
                    reach = true;
                }
            }
            if (reach) mins++;
            else break;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) 
                    return -1;
            }
        }
        return mins;
    }
}
