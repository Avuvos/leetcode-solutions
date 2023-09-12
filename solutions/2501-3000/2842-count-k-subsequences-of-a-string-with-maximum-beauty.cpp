class Solution {
public:
    const int MOD = 1e9 + 7;
    
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
    }
    
    long long inverse(long long a) {
        return expo(a, MOD - 2);
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> cnt(26, 0);
        int n = (int) s.size();
        
        vector<long long> f(n + 1);
        vector<long long> invf(n + 1);
        f[0] = f[1] = 1;
        invf[0] = invf[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] * i) % MOD;
            invf[i] = inverse(f[i]);
        }
        
        for (auto &c: s){
            cnt[c - 'a']++;
        } 
        
        map<int, int> mp;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                mp[cnt[i]]++;
            }
        }
        
        vector<pair<int, int>> v(mp.rbegin(), mp.rend());
        long long ans = 1;
        
        for (auto [key, value]: v) {
            long long cur = 1;
            if (k >= value) {
                cur = expo(key, value) % MOD;
                k -= value;
            } else {
                cur = ((expo(key, k) % MOD) * ((((f[value] * invf[k]) % MOD) * invf[value - k]) % MOD)) % MOD;
                k = 0;
            }
            ans = (ans * cur) % MOD;
            if (k == 0) break;
        }
        
        return k > 0 ? 0 : ans;
    }
};
