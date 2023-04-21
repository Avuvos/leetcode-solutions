class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        long long dp[101][101][101];
        memset(dp, -1, sizeof(dp));
        function<long long(int, int, int)> dfs = [&](int idx, int pep, int mon) {
            if (idx >= group.size()) return (mon >= minProfit ? 1ll : 0ll);
            if (dp[idx][pep][mon] != -1) return dp[idx][pep][mon];
            long long ans = 0;
            if (group[idx] <= pep) {
                ans += dfs(idx + 1, pep - group[idx], min(minProfit, mon + profit[idx] ));
            }
            ans += dfs(idx + 1, pep, mon);
            dp[idx][pep][mon] = ans % MOD;
            return ans % MOD;
        };
        return dfs(0, n, 0);
    }
};


//dp[index][members left][money]
//which means up to index, with memebers left, we made <= money
