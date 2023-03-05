class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int MOD = 1e9 + 7;
        int n = types.size();
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        for (int x = 1; x <= target; x++) {
            for (int i = 1; i <= n; i++) {
                int cnt = types[i - 1][0], mark = types[i - 1][1];
                for (int c = 0; c <= cnt; c++) {
                    int value = c * mark;
                    if (x - value >= 0) {
                        dp[x][i] += dp[x - value][i - 1];
                        dp[x][i] %= MOD;
                    }
                }
            }
        }
        return dp[target][n] % MOD;
    }
};
