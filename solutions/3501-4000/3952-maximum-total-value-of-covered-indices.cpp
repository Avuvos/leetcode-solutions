class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0LL));
        // dp[i][0] - max value up to i when prev has no token
        // dp[i][1] - max value up to i when prev has token
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                dp[i + 1][1] = nums[i] + max(dp[i][0], dp[i][1]); // keep the token
                dp[i + 1][0] = (i > 0 ? nums[i - 1] + dp[i][0] : 0); // push back the token
            } else {
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
                dp[i + 1][1] = 0;
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};
