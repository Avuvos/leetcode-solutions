class Solution {
public:
    int minCost(int n) {
        vector<int> dp(n + 1, 1e9+2);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= (i + 1) / 2; j++) {
                dp[i] = min(dp[i], j * (i - j) + dp[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
};
