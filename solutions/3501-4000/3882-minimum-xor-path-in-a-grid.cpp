class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mx = 1 << 10, inf = 1e9 + 2;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(mx, false)));
        dp[0][0][grid[0][0]] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = grid[i][j];
                for (int k = 0; k < mx; k++) {
                    if (i > 0 && dp[i - 1][j][k]) {
                        dp[i][j][k ^ val] = true;
                    }
                    if (j > 0 && dp[i][j - 1][k]) {
                        dp[i][j][k ^ val] = true;
                    }
                }
            }
        }
        for (int k = 0; k < mx; k++) {
            if (dp[n - 1][m - 1][k]) {
                return k;
            }
        }
        return -1;
    }
};
