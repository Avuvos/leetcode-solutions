class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long expo(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res *= a;
                res %= MOD;
            }
            a *= a;
            a %= MOD;
            b >>= 1;
        }
        return res;
    };

    int countVisiblePeople(int n, int pos, int k) {
        int left = pos, right = n - pos - 1;
        long long ans = 0;

        vector<long long> f(n + 1), invf(n + 1);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = (1LL * f[i - 1] * i) % MOD;
        }
        invf[n] = expo(f[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invf[i] = (1LL * invf[i + 1] * (i + 1)) % MOD;
        }
        auto choose = [&](int a, int b) -> long long {
            if (a < b) {
                return 0;
            }
            return (f[a] * invf[b] % MOD * invf[a - b]) % MOD;
        };

        for (int i = 0; i <= left; i++) {
            int j = k - i;
            if (j < 0 || j > right) continue;
            long long from_left = choose(left, i);
            long long from_right = choose(right, j);
            long long cur_res = 2 * from_left * from_right % MOD;
            ans = (ans + cur_res) % MOD;
        }
        return ans % MOD;
    }
};
