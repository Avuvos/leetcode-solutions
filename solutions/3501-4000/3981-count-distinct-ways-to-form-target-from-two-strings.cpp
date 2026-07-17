class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[101][101][101];
    int interleaveCharacters(string word1, string word2, string target) {
        int n = target.size(), m = word1.size(), l = word2.size();
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto &dfs, int i, int j, int k) -> long long {
            if (i == n) {
                return j > 0 && k > 0;
            }
            if (j >= m && k >= l) {
                return 0;
            }
            if (dp[i][j][k] != -1) {
                return dp[i][j][k];
            }
            long long ways = 0;
            for (int jj = j; jj < m; jj++) {
                if (target[i] == word1[jj]) {        
                    ways = (ways + dfs(dfs, i + 1, jj + 1, k)) % MOD;
                }
            }
            for (int kk = k; kk < l; kk++) {
                if (target[i] == word2[kk]) {        
                    ways = (ways + dfs(dfs, i + 1, j, kk + 1)) % MOD;
                }
            }
            return dp[i][j][k] = ways;
        };
        return dfs(dfs, 0, 0, 0);
    }
};
