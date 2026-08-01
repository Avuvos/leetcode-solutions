class Solution {
public:
    const int MOD = 1e9 + 7;

    long long expo(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inv(long long a) {
        return expo(a, MOD - 2);
    }

    int countValidSequences(int n, int k) {
        vector<long long> f(n + 1, 1), invf(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] * i) % MOD;
        }
        invf[n] = inv(f[n]);
        for (int i = n - 1; i >= 0; i--) {
            invf[i] = (invf[i + 1] * (i + 1)) % MOD;
        }
        auto C = [&](long long n, long long k) -> long long {
            if (k < 0 || k > n) return 0;            
            return f[n] * invf[k] % MOD * invf[n - k] % MOD;
        };

        long long total_seq = C(n - 1, k - 1);
        if ((n - k) & 1) {
            return total_seq;
        }
        long long odd_seq = C((n + k) / 2 - 1, k - 1);
        return (total_seq - odd_seq + MOD) % MOD;
    }
};
