class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int best = 1;
        for (int i = 1; i < n; i++) {
            for (int f = 0; f < 2; f++) {
                int p = nums[i - 1] + f;
                if (p + 1 == nums[i]) { //he either flipped or didnt, but its ok
                    dp[i][0] = max(dp[i][0], 1 + dp[i - 1][f]);
                }
                if (p == nums[i]) { //he is equal now, so we must flip ourselves
                    dp[i][1] = max(dp[i][1], 1 + dp[i - 1][f]);
                }
            }
            if (nums[i] == nums[i - 1]) {
                dp[i][0] = max(dp[i][0], dp[i - 1][0]);
                dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            }
            best = max(best, dp[i][0]);
            best = max(best, dp[i][1]);
        }
        return best;
    }
};
