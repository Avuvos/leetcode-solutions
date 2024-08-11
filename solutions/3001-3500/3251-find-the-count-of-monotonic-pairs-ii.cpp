class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = (int) nums.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(1002, 0));
        for (int x = 0; x <= 1000; x++) dp[0][x] = 1;
        
        //x >= p1
        //nums[i - 1] - x <= p2
        //x >= nums[i - 1] - p2
        
        for (int i = 1; i <= n; i++) {
            int bound = i > 1 ? nums[i - 2] : 1000;
            for (int p1 = 0; p1 <= bound; p1++) {
                int p2 = i > 1 ? nums[i - 2] - p1 : 1000;
                int l = max(p1, nums[i - 1] - p2), r = nums[i - 1];
                if (l > r) continue;
                dp[i][l] += (dp[i - 1][p1]);
                dp[i][r + 1] -= (dp[i - 1][p1]);
            }
            for (int x = 1; x <= 1000; x++) {
                dp[i][x] += dp[i][x - 1];
                dp[i][x] %= MOD;
            }
        }
        return dp[n][nums.back()];
    }
};
