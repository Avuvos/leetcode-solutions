class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums1.size();
        vector<array<int, 2>> dp(n);
        dp[0][0] = dp[0][1] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            //either put nums1 or nums2
            //if we put nums1 we can either take the prev nums1 or the prev nums2.
            dp[i][0] = 1;
            dp[i][1] = 1;
            if (nums1[i - 1] <= nums1[i]) {
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            }
            if (nums2[i - 1] <= nums1[i]) {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            }
            if (nums1[i - 1] <= nums2[i]) {
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            }
            if (nums2[i - 1] <= nums2[i]) {
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            }
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};
