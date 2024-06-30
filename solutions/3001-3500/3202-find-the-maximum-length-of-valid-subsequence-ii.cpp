class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> dp(k, 0);
        for (int r = 0; r < k; r++) {
            for (auto x: nums) {
                x %= k;
                dp[x] = max(dp[x], dp[(r - x + k) % k] + 1);  
                ans = max(ans, dp[x]);
            }
            dp.assign(k, 0);
        }
        return ans;
    }
};
