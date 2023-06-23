class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //dp[i][j] is the longest subseq ending at i with diff j.
        //dp[i][j] = look for some k < j such that , and a[i] - a[k] = j.
        //diff can be at most 1000 including negatives, so we are okay?
        int n = (int) nums.size();
        int maxValue = 1005;
        vector<vector<int>> dp(n + 1, vector<int>(maxValue, 1));
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int d = nums[i] - nums[j];
                if (d < 0) d = abs(d) + 501;
                dp[i][d] = max(dp[i][d], 1 + dp[j][d]);
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};
