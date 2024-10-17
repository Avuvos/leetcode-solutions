class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        const int MOD = 1e9 + 7;
        
        // calc stirling number of the second kind
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % MOD;
            }
        }
       
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
        
         //calc factorial
        int m = n + x + 2;
        vector<long long> f(m, 1);
        for (int i = 2; i < m; i++) {
            f[i] = (1LL * i * f[i - 1]) % MOD;
        }
        
        auto choose = [&](int n, int k) -> long long {
            if (k < 0 || k > n) return 0;
            return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD; 
        };
        
        /* we choose:
        1. number of stages - k
        2. the actual stages choose(x, k)
        3. arrange those stages f[k]
        4. the score of each stage expo(y, k)
        5. the distribution of people for each stage dp[n][k]
        */
        
        long long ans = 0;
        for (int k = 1; k <= min(n, x); k++) {
            ans = (ans + expo(y, k) * choose(x, k) % MOD * f[k] % MOD * dp[n][k]) % MOD;
        }
        return ans;
    }
};
