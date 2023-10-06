class Solution {
public:
    int integerBreak(int n) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for (long long i = 2; i <= n; i++) {
            for (long long j = 1; j <= i - 1; j++) {
                dp[i] = max(dp[i], 1LL * max(dp[j], j) * max(dp[i - j], i - j));
            }
        }
        return dp[n];
    }
};
