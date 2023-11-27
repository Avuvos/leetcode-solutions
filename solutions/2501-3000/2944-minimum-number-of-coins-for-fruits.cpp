class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = (int) prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        auto dfs = [&](auto dfs, int index, int covered) -> int {
            if (index >= n) {
                return 0;
            }
            if (dp[index][covered] != -1) {
                return dp[index][covered];
            }
            int take = 1e9, skip = 1e9;
            take = prices[index] + dfs(dfs, index + 1, min(n, index + index + 2));
            if (index < covered) {
                skip = dfs(dfs, index + 1, covered);
            }
            return dp[index][covered] = min(take, skip);
        };
        return dfs(dfs, 0, 0);
    }
};
