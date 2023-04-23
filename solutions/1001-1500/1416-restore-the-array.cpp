class Solution {
public:
    typedef long long ll;
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = (int) s.size();
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0 : 1);
        for (int index = 1; index < n; index++) {
            //dp[index + 1]
            ll num = (s[index] - '0');
            if (num > 0 && num <= k) {
                dp[index + 1] += dp[index];
                dp[index + 1] % MOD;
            }
            ll mult = 10;
            for (int p = index - 1; p >= 0; p--) {
                if (index - p > 10) break;
                num += mult*(s[p] - '0');
                if (num > k) break;
                mult *= 10;
                if (s[p] == '0') continue;
                dp[p] %= MOD;
                dp[index + 1] += dp[p];
                dp[index + 1] % MOD;
                if (mult > k) break;
            }
        }
        return dp[n] % MOD;
        
//         const int MOD = 1e9 + 7;
//         int n = (int) s.size();
//         vector<ll> dp(n + 1, -1);
        
//         function<ll(int)> dfs = [&](int index) {
//             if (index >= n) return 1ll;
//             if (s[index] == '0') return 0ll;
//             if (dp[index] != -1) return dp[index];
//             ll ans = 0;
//             ll num = 0;
//             vector<int> pos;
//             for (int i = index; i < n; i++) {
//                 num += (s[index] - '0');
//                 if (num > k) break;
//                 if (num >= 1) pos.push_back( i+ 1);
//                 num *= 10;
//             }
//             for (auto &p: pos) {
//                 ans += dfs(p);
//                 ans %= MOD;
//             }
//             dp[index] = ans % MOD;
//             return dp[index];
//         };
//         return dfs(0);
    }
};
