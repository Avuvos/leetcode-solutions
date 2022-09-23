class Solution {
public:

    int concatenatedBinary(int n) {
        long long res = 0, mod = 1e9 + 7;
        for (int num = 1; num <= n; ++num) {
            int len = log2(num) + 1;
            res = ((res << len) % mod + num) % mod;
        }
        return res % mod;
    }
};
