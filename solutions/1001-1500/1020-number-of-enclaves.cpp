class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
            grid[x][y] = 0;
            return 1 + dfs(x + 1, y)
                     + dfs(x - 1, y)
                     + dfs(x, y + 1)
                     + dfs(x, y - 1);
        };
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        dfs(i, j);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }
};
