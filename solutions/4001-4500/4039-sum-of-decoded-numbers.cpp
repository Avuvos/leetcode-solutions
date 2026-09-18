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

    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for (auto &x: nums) {
            string d = to_string(x / 10);
            int w = x % 10;
            long long xi = stoll(d.substr(0, w));
            long long yi = stoll(d.substr(w));
            ans = (ans + expo(xi, yi)) % MOD;
        }
        return ans;
    }
};
