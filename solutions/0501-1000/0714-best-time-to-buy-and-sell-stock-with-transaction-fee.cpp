class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int) prices.size();
        vector<array<int, 2>> dp(n + 1);
        dp[0][0] = 0;
        dp[0][1] = -1e9;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i] - fee);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
