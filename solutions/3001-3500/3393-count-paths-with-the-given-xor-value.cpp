class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size(), max_k = 17;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(max_k, 0)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int x = 0; x < max_k; x++) {
                    if (dp[i][j][x] == 0) continue;
                    if (j + 1 < m) {
                        int nx = x ^ grid[i][j + 1];
                        dp[i][j + 1][nx] = (dp[i][j + 1][nx] + dp[i][j][x]) % MOD;
                    }
                    if (i + 1 < n) {
                        int nx = x ^ grid[i + 1][j];
                        dp[i + 1][j][nx] = (dp[i + 1][j][nx] + dp[i][j][x]) % MOD;
                    }
                }
            }
        }
        return dp[n - 1][m - 1][k];
    }
};
