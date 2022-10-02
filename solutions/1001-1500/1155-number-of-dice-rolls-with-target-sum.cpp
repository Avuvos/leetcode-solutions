class Solution {
public:
    int numRollsToTarget(int dices, int k, int target) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(dices + 1, vector<int>(target + 1, 0));
        for (int d = 1; d <= dices; d++) {
            for (int amount = 1; amount <= target; amount++)
                for (int j = 1; j <= k; j++) {
                    if (d == 1 && amount <= k) {
                        dp[d][amount] = 1;
                    }
                    else if (amount - j >= 0) {
                        dp[d][amount] += dp[d - 1][amount - j];
                        dp[d][amount] %= MOD;
                    }
                }
            }
        return dp[dices][target] % MOD;
    }
};
