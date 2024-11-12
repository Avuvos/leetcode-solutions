class Solution {
public:
    int countBalancedPermutations(string num) {
        
        
        const int MOD = 1e9 + 7;
        int n = num.size();
        
        auto expo = [&](long long a, long long b) -> long long {
            long long res = 1;
            while (b > 0) {
                if (b & 1) {
                    res = (res * a) % MOD;
                }
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        };
        
        auto inv = [&](long long a) -> long long {
            return expo(a, MOD - 2);
        };
        
        
        vector<long long> f(n + 1, 1), invf(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            f[i] = (1LL * i * f[i - 1]) % MOD;
            invf[i] = inv(f[i]);
        }
        
        auto choose = [&](int n, int k) -> long long {
            if (k > n) return 0;
            return f[n] * invf[n - k] % MOD * invf[k] % MOD;
        };
        
        vector<int> cnt(10, 0);
        int mx_s = 2;
        for (auto &x: num) {
            cnt[x - '0']++;
            mx_s += (x - '0');
        }
        
        vector<vector<vector<int>>> dp(10, vector<vector<int>>(2 * mx_s + 1, vector<int>((n + 1)/2 + 1, -1)));
        auto dfs = [&](auto &dfs, int index, int sum, int odds) -> long long {
            if (odds > (n + 1) / 2) {
                return 0;
            }
            if (index >= 10) {
                return sum == 0 && odds == (n + 1) / 2;
            }
            if (dp[index][sum + mx_s][odds] != -1) {
                return dp[index][sum + mx_s][odds];
            }
            long long ans = 0;
            int tot = 0;
            for (int i = 0; i < index; i++) tot += cnt[i];
            int even = tot - odds;
            for (int d = 0; d <= cnt[index]; d++) {
                int ed = cnt[index] - d;
                if (n / 2 - even < 0) continue;
                if ((n + 1) / 2 - odds < 0) continue;
                int ns = sum + ed * index - d * index;
                ans = (ans + dfs(dfs, index + 1, ns, odds + d)%MOD * choose(n / 2 - even, ed)%MOD * choose((n + 1) / 2 - odds, d)%MOD)%MOD;
            }
            return dp[index][sum + mx_s][odds] = ans % MOD;
        };
        long long ans = 0;
        ans = dfs(dfs, 0, 0, 0);
        return ans;
    }
};
