class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
    
                if (dp[i] < dp[j] + 1) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                } else if (dp[i] == dp[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
        }
        int best = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == best) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
