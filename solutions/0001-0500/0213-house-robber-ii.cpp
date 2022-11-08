class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        auto robber = [&](int start, int end) {
            if (n == 1) return nums[0];
            if (n == 2) return max(nums[0], nums[1]);
            vector<int> dp(n, 0);
            dp[start] = nums[start];
            dp[start + 1] = max(nums[start], nums[start + 1]);
            for (int i = start + 2; i < n; i++) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            return dp[end - 1];
        };
        return max(robber(0, n - 1), robber(1, n));
    }
};
