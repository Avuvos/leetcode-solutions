class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(mx + 1, vector<int>(mx + 1, -1)));
        auto dfs = [&](auto &dfs, int i, int g1, int g2) -> int {
            if (i >= n) {
                return g1 == g2 && g1 > 0;
            }
            if (dp[i][g1][g2] != -1) {
                return dp[i][g1][g2];
            }
            int take1 = dfs(dfs, i + 1, gcd(g1, nums[i]), g2) % MOD;
            int take2 = dfs(dfs, i + 1, g1, gcd(g2, nums[i])) % MOD;
            int skip = dfs(dfs, i + 1, g1, g2) % MOD;
            return dp[i][g1][g2] = ((take1 + take2)%MOD + skip) % MOD;
        };
        return dfs(dfs, 0, 0, 0);
    }
};
