class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (auto &x: nums) {
            target |= x;
        }
        vector<int> dp(1 << 18, 0);
        dp[0] = 1;
        for (auto &x: nums) {
            for (int i = target; i >= 0; i--) {
                dp[x | i] += dp[i];
            }
        }
        return dp[target];
    }
};
