class Solution {
public:
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), mod = 1e9 + 7;
        auto expo = [&](ll a, ll b) -> ll {
            ll res = 1;
            while (b > 0) {
                if (b & 1) {
                    res *= a;
                    res %= mod;
                }
                a *= a;
                a %= mod;
                b /= 2;
            }
            return res;
        };

        auto inverse = [&](ll a) -> ll {
            return expo(a, mod - 2);
        };

        vector<ll> ps(n + 1, 0), px(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] =(ps[i] + (s[i] - '0')) % mod;
        }
        long long mult = 1;
        vector<int> div(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                px[i] = (px[i + 1] + (mult * (s[i] - '0')) % mod) % mod;
                mult = (10 * mult) % mod;
                div[i]++;
            } else {
                px[i] = px[i + 1];
            }
            div[i] += div[i + 1];
        }
        ll inv_ten = inverse(10);
        vector<int> ans;
        for (auto &q: queries) {
            int l = q[0], r = q[1];
            ll sum = (ps[r + 1] - ps[l] + mod) % mod;
            ll x = (px[l] - px[r + 1] + mod) % mod * expo(inv_ten, div[r + 1]) % mod;
            ans.push_back((x * sum) % mod);
        }
        return ans;
    }
};
