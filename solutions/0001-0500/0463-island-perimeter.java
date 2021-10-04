class Solution {
    public int islandPerimeter(int[][] grid) {
        int res = 0, n = grid.length, m = grid[0].length;
        Queue<int []> q = new LinkedList<>();
        boolean found = false;
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { //find the first cell with a 1
                    q.offer(new int[] {i ,j});
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        while (!q.isEmpty()) { //BFS
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                if (grid[x][y] == 2) continue;
                grid[x][y] = 2; //mark as visited

                //if neigh out of bounds or water, add 1 to res
                if (x + 1 >= n || grid[x + 1][y] == 0) {
                    res++;
                }
                //otherwise if its another land, put it in the q
                else if (grid[x + 1][y] == 1) {
                    q.offer(new int[]{x + 1, y});
                }
                
                if (x - 1 < 0 || grid[x - 1][y] == 0)  {
                    res++;
                }
                else if (grid[x - 1][y] == 1) {
                    q.offer(new int[]{x - 1, y});    
                }

                if (y + 1 >= m || grid[x][y + 1] == 0) {
                    res++;
                }
                else if (grid[x][y + 1] == 1) {
                    q.offer(new int[]{x, y + 1});
                }

                if (y - 1 < 0 || grid[x][y - 1] == 0) {
                    res++;
                }
                else if (grid[x][y - 1] == 1){
                    q.offer(new int[]{x, y - 1});
                }
            }
        }
        return res;
    }
}
