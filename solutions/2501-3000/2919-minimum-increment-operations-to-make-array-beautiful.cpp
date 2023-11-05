class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = (int) nums.size();
        long long INF = 1e16;
        vector<vector<long long>> dp(n, vector<long long>(3, -1));
        auto dfs = [&](auto dfs, int index, int skip) -> long long {
            if (skip >= 3) {
                return INF;
            }
            if (index >= n) {
                return 0;
            }
            if (dp[index][skip] != -1) {
                return dp[index][skip];
            }
            long long ans = INF;
            long long cost = max(0, k - nums[index]);
            ans = min(ans, cost + dfs(dfs, index + 1, 0));
            ans = min(ans, cost + dfs(dfs, index + 2, 1));
            ans = min(ans, cost + dfs(dfs, index + 3, 2));
            ans = min(ans, dfs(dfs, index + 1, skip + 1));
            ans = min(ans, dfs(dfs, index + 2, skip + 2));
            return dp[index][skip] = ans;
        };
        return dfs(dfs, 0, 0);
    }
};
