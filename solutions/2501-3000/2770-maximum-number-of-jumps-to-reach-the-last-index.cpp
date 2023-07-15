class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = (int) nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) { 
                if (dp[j] > -1 && nums[i] - nums[j] <= target && nums[i] - nums[j] >= -target)
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return dp[n - 1];
    }
};
