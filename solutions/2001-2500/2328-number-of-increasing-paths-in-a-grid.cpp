class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<long long(int, int)> dfs = [&](int x, int y) {
            if (dp[x][y] != -1) return dp[x][y];
            dp[x][y] = 0;
            for (auto [dx, dy]: vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[x][y] < grid[nx][ny]) {
                    dp[x][y] += 1 + dfs(nx, ny);
                    dp[x][y] %= MOD;
                }
            }
            return dp[x][y];
        };
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    dfs(i, j);
                }
                ans += dp[i][j];
                ans %= MOD;
            }
        }
        return (ans + n*m) % MOD;
        
    }
};
