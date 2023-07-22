class Solution {
public:
    typedef long long ll;
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        
        if (true) {
            //using only the first coin coins
            vector<ll> dp(n + 1, 0);
            dp[0] = 1;
            for (int coin = 1; coin <= n; coin++) {
                ll p = pow(coin, x); 
                for (int num = n; num >= 1; num--) {
                    if (num - p < 0) continue; 
                    dp[num] += dp[num - p];
                    dp[num] %= MOD;
                }
            }
            return dp[n];
        }
                
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
        function<ll(ll, ll)> dfs = [&](ll num, ll bound) -> ll {
            if (num == n) return 1;
            if (dp[num][bound] != -1) return dp[num][bound];
            ll ans = 0;
            for (int k = bound; k <= n; k++) {
                ll p = pow(k, x);
                if (num + p > n) break;
                ans += dfs(num + p, k + 1);
                ans %= MOD;
            }
            dp[num][bound] = ans % MOD;
            return ans;
        };
        return (int)(dfs(0, 1) % MOD);
    }
};
