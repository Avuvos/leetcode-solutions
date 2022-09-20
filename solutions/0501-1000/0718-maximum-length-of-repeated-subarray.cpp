class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n = nums1.size(), m = nums2.size();
        //dp[i][j] = max subarray ENDING at i and j
        //we need max(dp[i][j]) for all i and j
        //dp[i][j] = nums1[i]==nums2[j] ? dp[i - 1][j - 1] + 1 : 0
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = nums1[i] == nums2[j];
                }
                else {
                    dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
