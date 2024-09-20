class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), pos = 0, mod = 1e9 + 7, p = 31;
        if (n == 0) return s;
        long long hash_prefix = 0, hash_reversed_prefix = 0, p_pow_i = 1;
        for (int i = 0; i < n; i++, p_pow_i = (p_pow_i * p) % mod) {
            hash_prefix = (hash_prefix * p + (s[i] - 'a' + 1)) % mod;
            hash_reversed_prefix = (hash_reversed_prefix + (s[i] - 'a' + 1) * p_pow_i) % mod;
            if (hash_prefix == hash_reversed_prefix) {
                pos = i;
            }
        }
        string t = s.substr(pos + 1);
        reverse(t.begin(), t.end());
        return t + s;
    }
};
