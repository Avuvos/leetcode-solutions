class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0, n = (int) nums.size();
        if (n <= 2) return true;
        for (auto &a: nums) sum += a;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        function<int(int, int, int)> dfs = [&](int l, int r, int sum) -> int {
            if (l >= r) {
                return 1;
            }
            if (dp[l][r] != -1) {
                return dp[l][r];
            }
            if (sum < m) {
                return 0;
            }
            return dp[l][r] = dfs(l + 1, r, sum - nums[l]) | dfs(l, r - 1, sum - nums[r]);
        };
        return dfs(0, n - 1, sum);
    }
};
