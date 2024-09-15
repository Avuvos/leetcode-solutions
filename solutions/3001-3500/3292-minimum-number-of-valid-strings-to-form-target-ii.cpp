typedef long long ll;
struct StringHasher {
    int size;
    int p;
    int mod;
    char default_char; //probably one of {0, a, A}
    vector<ll> p_pow;

    StringHasher(int size, int p = 31, int mod = 1e9 + 7, char default_char = 'a') {
        this->size = size;
        this->p = p;
        this->mod = mod;
        this->default_char = default_char;
        init_p_pow();
    }

    void init_p_pow() {
        p_pow.resize(size + 1);
        p_pow[0] = 1;
        for (int i = 1; i <= size; i++) {
            p_pow[i] = (p_pow[i - 1] * p) % mod;
        }
    }

    char get(char c) {
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
    int minValidStrings(vector<string>& words, string target) {
        int n = words.size();
        StringHasher st = StringHasher(int(1e5+2));
        vector<vector<ll>> hashes;
        for (auto &word: words) {
            hashes.push_back(st.calc_prefix_hash(word));
        }
        const int inf = 1e9 + 2;
        int m = target.size();
        vector<ll> target_hs = st.calc_prefix_hash(target);
        vector<int> dp(m + 1, inf);
        dp[0] = 0;
        set<int> todo;
        for (int i = 1; i <= m; i++) {
            todo.insert(i);
        }
        for (int i = 0; i < m && dp[m] >= inf; i++) {
            if (dp[i] >= inf) continue;
            for (int j = 0; j < n; j++) {
                vector<ll>& hs = hashes[j];
                int l = 0, r = min((int)hs.size() - 1, m - i - 1), res = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (st.calc_substring_hash(target_hs, i, i + mid) == st.calc_substring_hash(hs, 0, mid)) {
                        res = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (res == -1) continue;
                auto it = todo.lower_bound(i);
                vector<int> to_remove;
                while (it != todo.end() && *it <= i + res + 1) {
                    dp[*it] = min(dp[*it], 1 + dp[i]);
                    to_remove.push_back(*it);
                    it = next(it);
                }
                for (auto &idx: to_remove) {
                    todo.erase(idx);
                }
            }
        }
        return dp[m] < inf ? dp[m] : -1;
    }
};
