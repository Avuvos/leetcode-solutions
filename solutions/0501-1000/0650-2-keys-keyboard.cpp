class Solution {
public:
    int minSteps(int n) {
        const int inf = 1e9 + 2;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
        dp[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == inf) continue;
                dp[i][i] = min(dp[i][i], 1 + dp[i][j]);
                if (i + j <= n) {
                    dp[i + j][j] = min(dp[i + j][j], 1 + dp[i][j]);
                }
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};
