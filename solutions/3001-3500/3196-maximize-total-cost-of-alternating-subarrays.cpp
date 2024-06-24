class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        
        int n = (int) nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        auto dfs = [&](auto &dfs, int index, int sign) -> long long {
            if (index >= n) {
                return 0;
            }
            if (dp[index][sign] != -1) {
                return dp[index][sign];
            }
            long long new_subarray = nums[index] + dfs(dfs, index + 1, 0);
            long long continue_subarray = nums[index] * (sign == 0 ? -1 : 1) + dfs(dfs, index + 1, sign ^ 1);
            return dp[index][sign] = max(new_subarray, continue_subarray);
        };
        
        return dfs(dfs, 0, 1);
    }
};
