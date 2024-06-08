class Solution {
public:
    const int inf = 1e9 + 2;
    int dp[5001][51];
    int maximumLength(vector<int>& nums, int k) {
        int n = (int) nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = 1; //only i is included
                for (int p = i - 1; p >= 0; p--) {
                    //try to join a sequence that ends at p
                    int pen = nums[p] != nums[i];
                    if (j - pen >= 0) {
                        dp[i][j] = max(dp[i][j], 1 + dp[p][j - pen]);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
