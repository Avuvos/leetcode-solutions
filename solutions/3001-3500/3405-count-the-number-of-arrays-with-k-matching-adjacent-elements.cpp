class Solution {
public:
    typedef long long ll;
    int countGoodArrays(int n, int m, int k) {
        const int MOD = 1e9 + 7;
        auto expo = [&](ll a, ll b) -> ll {
            ll res = 1;
            while (b > 0) {
                if (b & 1) {
                    res = (res * a) % MOD;
                }
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        };
        auto inv = [&](ll a) -> ll {
            return expo(a, MOD - 2);
        };
        int N = n + 1;
        vector<ll> f(N, 1), invf(N, 1);
        for (int i = 2; i < N; i++) {
            f[i] = (1ll * f[i - 1] * i) % MOD;
            invf[i] = inv(f[i]);
        }
        auto choose = [&](ll n, ll k) -> ll {
            if (k > n || k < 0 || n < 0) return 0;
            return ((f[n] * invf[n - k]) % MOD * invf[k]) % MOD;
        };
        ll ans = m * expo(m - 1, n - 1 - k) % MOD;
        ans = (ans * choose(n - 1, k)) % MOD;
        return ans;
    }
};
