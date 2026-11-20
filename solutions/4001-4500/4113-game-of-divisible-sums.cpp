class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        auto dfs = [&](auto &dfs, int i) -> long long {
            if (i >= n) {
                return 0;
            }
            if (i == n - 1) {
                return nums[i];
            }
            if (dp[i] != -1) {
                return dp[i];
            }
            long long s1 = nums[i], s2 = nums[i] + nums[i + 1];
            long long op1 = s1 + (s1 % 3 == 0 ? -dfs(dfs, i + 1) : dfs(dfs, i + 1));
            long long op2 = s2 + (s2 % 3 == 0 ? -dfs(dfs, i + 2) : dfs(dfs, i + 2));
            return dp[i] = max(op1, op2);
        };
        return dfs(dfs, 0);
    }
};
