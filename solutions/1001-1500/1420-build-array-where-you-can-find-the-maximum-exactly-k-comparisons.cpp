class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    ll dp[51][101][51];
    int numOfArrays(int n, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        memset(dp, -1, sizeof(dp));
        function<ll(int, int, int)> dfs = [&](int index, int mx, int cost) -> ll {
            if (index >= n) {
                return cost == k;
            }
            if (cost > k || n - index < k - cost) {
                return 0;
            }
            if (dp[index][mx][cost] != -1) {
                return dp[index][mx][cost];
            }
            ll ans = 0;
            for (int i = mx + 1; i <= m; i++) {
                ans += dfs(index + 1, i, cost + 1);
                ans %= MOD;
            }
            ans += ((mx * dfs(index + 1, mx, cost)) % MOD);
            ans %= MOD;
            return dp[index][mx][cost] = ans;
        };
        return dfs(0, 0, 0);
    }
};
