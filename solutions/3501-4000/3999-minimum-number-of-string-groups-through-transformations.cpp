typedef long long ll;

const int MAX_N = 5e5;
const int P = 31;
const int MOD = 1e9 + 7;

ll p_pow[2 * MAX_N + 1];

struct StringHasher {
    int p;
    int mod;
    char default_char;

    StringHasher(int p = P, int mod = MOD, char default_char = 'a') {
        this->p = p;
        this->mod = mod;
        this->default_char = default_char;
    }

    int get(char c) {
        return c - default_char + 1;
    }

    vector<ll> calc_prefix_hash(string& s) {
        int n = (int) s.size();
        vector<ll> prefix_hash(n, 0);
        prefix_hash[0] = get(s[0]);
        for (int i = 1; i < n; i++) {
            prefix_hash[i] = (prefix_hash[i - 1] * p + get(s[i])) % mod;
        }
        return prefix_hash;
    }

    //[l, r] (both inclusive)
    ll calc_substring_hash(vector<ll>& prefix_hash, int l, int r) {
        if (l == 0) {
            return prefix_hash[r];
        }
        ll ans = (prefix_hash[r] - prefix_hash[l - 1] * p_pow[r - l + 1]) % mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};

class Solution {
public:
    int minimumGroups(vector<string>& words) {
        if (p_pow[0] != 1) {
            p_pow[0] = 1;
            for (int i = 1; i <= 2 * MAX_N; i++) {
                p_pow[i] = (p_pow[i - 1] * P) % MOD;
            }
        }
        StringHasher hs;
        set<pair<ll, ll>> st;

        auto get = [&](string &s) -> ll {
            int sz = s.size();
            if (sz == 0) return 0;
            string cs = s + s;
            vector<ll> ph = hs.calc_prefix_hash(cs);
            ll mn_hash = LLONG_MAX;
            for (int j = 0; j < sz; j++) {
                ll val = hs.calc_substring_hash(ph, j, j + sz - 1);
                mn_hash = min(mn_hash, val);
            }
            return mn_hash;
        };

        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            vector<string> subs(2);
            for (int j = 0; j < words[i].size(); j++) {
                subs[j % 2].push_back(words[i][j]);
            }
            ll hse = get(subs[0]);
            ll hso = get(subs[1]);
            if (!st.contains({hse, hso})) {
                st.insert({hse, hso});
                ans++;
            }
        }
        return ans;
    }
};
