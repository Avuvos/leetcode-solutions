class Solution {
public:
    int change(int n, vector<int>& coins) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (auto &c: coins) {
            for (int i = 1; i <= n; i++) {
                if (i - c >= 0) {
                    dp[i] += dp[i - c];
                }
            }
        }
        return dp[n];
    }
};
