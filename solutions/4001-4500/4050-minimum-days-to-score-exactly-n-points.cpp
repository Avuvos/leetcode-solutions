class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, 1e9 + 2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k * (k + 1) <= 2 * i; k++) {                
                int pts = k * (k + 1) / 2;
                int add_skip = (i == pts ? 0 : 1);
                dp[i] = min(dp[i], k + dp[i - pts] + add_skip);
            }
        }
        return dp[n];
    }
};
