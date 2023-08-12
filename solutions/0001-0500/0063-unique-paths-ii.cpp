class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                dp[i + 1][j + 1] += dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[n][m];
    }
};
