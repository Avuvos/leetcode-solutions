class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int c = 0; c < m - 1; c++) {
            for (int r = 0; r < n; r++) {
                if (dp[r][c] == 0 && c > 0) continue;
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    dp[r - 1][c + 1] = max(dp[r - 1][c + 1], 1 + dp[r][c]);
                }
                if (grid[r][c] < grid[r][c + 1]) {
                    dp[r][c + 1] = max(dp[r][c + 1], 1 + dp[r][c]);
                }
                if (r + 1 < n && grid[r][c] < grid[r + 1][c + 1]) {
                    dp[r + 1][c + 1] = max(dp[r + 1][c + 1], 1 + dp[r][c]);
                }
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                ans = max(ans, dp[r][c]);
            }
        }
        return ans;
    }
};
