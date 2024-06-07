class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = (int) nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto dfs = [&](auto dfs, int l, int r) -> int {
            if (l > r) {
                return 0;
            }
            if (dp[l][r] != -1) {
                return dp[l][r];
            }
            if (dp[r][l] != -1) {
                return dp[r][l];
            }
            int ans = 0;
            for (int i = l + 1; i < r; i++) {
                int value = nums[i] * nums[l] * nums[r];
                ans = max(ans, value + dfs(dfs, i, r) + dfs(dfs, l, i));
            }
            return dp[l][r] = ans;
        };
        
        return dfs(dfs, 0, n - 1);
    }
};
