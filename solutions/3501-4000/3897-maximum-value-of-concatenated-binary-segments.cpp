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
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size(), len = 0, ans = 0;
        vector<tuple<int, int, int>> vals(n);
        for (int i = 0; i < n; i++) {
            len += (nums1[i] + nums0[i]);
            vals[i] = {nums0[i] == 0 ? 0: 1 , -nums1[i], nums0[i]};     
        }
        len -= 1;
        sort(vals.begin(), vals.end());
        for (auto [_, v1, v0]: vals) {
            v1 *= -1;
            for (int bit = len; bit > len - v1; bit--) {
                ans = (ans + expo(2, bit)) % MOD;
            }
            len -= (v1 + v0);
        }
        return ans;
    }
};
