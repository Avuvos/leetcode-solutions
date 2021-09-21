class Solution {
    public int getMaximumGold(int[][] grid) {
        int maxGold = 0;
        for (int i=0; i<grid.length; i++) {
            for (int j=0; j<grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    maxGold = Math.max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }

    //returns maximum gold path starting from position x,y
    public int dfs(int[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) {
            return 0;
        }
        int gold = grid[x][y];
        grid[x][y] = 0;
        int down = dfs(grid, x+1, y);
        int up = dfs(grid, x-1, y);
        int right = dfs(grid, x, y+1);
        int left = dfs(grid, x, y-1);
        grid[x][y] = gold;
        return gold + Math.max(Math.max(down, up), Math.max(right, left));
    }

}
