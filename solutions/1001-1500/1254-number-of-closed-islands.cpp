class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        int ans = 0;
        
        function<void(int, int)> dfs = [&](int x, int y) -> void {
            if (x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == 1) return;
            grid[x][y] = 1;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
