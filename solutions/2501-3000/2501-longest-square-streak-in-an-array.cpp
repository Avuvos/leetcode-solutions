class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        unordered_map<long long, int> dp;
        int best = -1;
        for (auto &x: nums) {
            long long y = 1LL * x * x;
            dp[x] = 1;
            if (dp.contains(y)) {
                dp[x] += dp[y];
                best = max(best, dp[x]);
            }
        }
        return best;
    }
};
