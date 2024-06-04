class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    ll dp[100001][2][3][2];
    
    ll dfs(int n, int cnt, int l, int e, int t) {
        if (cnt == n) {
            return (l == 1) && (e == 2) && (t == 1);
        }
        if (dp[cnt][l][e][t] != -1) {
            return dp[cnt][l][e][t] % MOD;
        }
        ll ans = 0;
        ans += dfs(n, cnt + 1, min(1, l + 1), e, t) % MOD;
        ans += dfs(n, cnt + 1, l, min(2, e + 1), t) % MOD;
        ans += dfs(n, cnt + 1, l, e, min(1, t + 1)) % MOD;
        ans += (23 * dfs(n, cnt + 1, l, e, t)) % MOD;
        return dp[cnt][l][e][t] = ans % MOD;
    }
    
    int stringCount(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (n < 4) return 0;
        memset(dp, -1, sizeof(dp));
        return dfs(n, 0, 0, 0, 0);   
    }
};
