class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = (int) a.size();
        int m = (1 << n);
        const int inf = 1e9 + 2;
        vector<int> dp(m + 1, inf);
        dp[0] = 0;
        for (int mask = 0; mask < m - 1; mask++) {
            int index = __builtin_popcount(mask);
            for (int j = 0; j < n; j++) {
                if (!((mask >> j) & 1)) {
                    dp[mask | (1 << j)] = min(dp[mask | (1 << j)], 
                                             dp[mask] + (a[index] ^ b[j]));
                }
            }
        }
        return dp[m - 1];
    }
};
