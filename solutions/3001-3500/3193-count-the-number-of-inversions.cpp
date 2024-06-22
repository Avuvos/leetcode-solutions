class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        sort(requirements.begin(), requirements.end());
        vector<int> req(n + 1, -1);
        for (auto& r: requirements) {
            req[r[0] + 1] = r[1];
        }
        int mx = requirements.back()[1];
        vector<vector<ll>> dp(n + 1, vector<ll>(mx + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= mx; j++) {
                for (int k = 1; k <= i; k++) {
                    if (j >= i - k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - (i - k)]) % MOD;
                    }
                }
            }
            for (int j = 0; j <= mx; j++) {
                if (req[i] != -1 && req[i] != j) {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][mx];
    }
};
