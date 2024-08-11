class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(51, vector<long long>(51, -1)));
        const int MOD = 1e9 + 7;
        
        auto dfs = [&](auto &dfs, int index, int p1, int p2) -> long long {
            if (index >= n) {
                return 1;
            }
            if (dp[index][p1][p2] != -1) {
                return dp[index][p1][p2];
            }
            long long ans = 0;
            for (int x = 0; x <= nums[index]; x++) {
                int y = nums[index] - x;
                if (x >= p1 && y <= p2) {
                    ans += dfs(dfs, index + 1, x, y);
                    ans %= MOD;
                }
            }
            return dp[index][p1][p2] = ans;
        };
        return dfs(dfs, 0, 0, 50);
    }
};
