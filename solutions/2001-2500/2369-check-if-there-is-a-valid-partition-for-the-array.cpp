class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = nums[0] == nums[1];
        
        for (int i = 2; i < n; i++) {
            dp[i + 1] |= dp[i - 1] && nums[i - 1] == nums[i];
            dp[i + 1] |= dp[i - 2] && nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i];
            dp[i + 1] |= dp[i - 2] && nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i];
        }
        return dp[n];
    }
};
