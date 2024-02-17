class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = (int) nums.size();
        int s1 = nums[0] + nums[1];
        int s2 = nums[n - 1] + nums[n - 2];
        int s3 = nums[0] + nums[n - 1];
        
        
        auto check = [&](int target) {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            auto dfs = [&](auto dfs, int l, int r) -> int {
                if (l >= r) {
                    return 0;
                }
                if (dp[l][r] != -1) {
                    return dp[l][r];
                }
                int ans = 0;
                if (nums[l] + nums[l + 1] == target) {
                    ans = max(ans, 1 + dfs(dfs, l + 2, r));
                }
                if (nums[r] + nums[r - 1] == target) {
                    ans = max(ans, 1 + dfs(dfs, l, r - 2));
                }
                if (nums[l] + nums[r] == target) {
                    ans = max(ans, 1 + dfs(dfs, l + 1, r - 1));
                }
                return dp[l][r] = ans;
            };
            return dfs(dfs, 0, n - 1);
        };
        
        int ans1 = check(s1);
        int ans2 = check(s2);
        int ans3 = check(s3);
        return max({ans1, ans2, ans3});
    }
};
