class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        if (a > b) {
            swap(a, b);
        }
        const int MOD = 1e9 + 7;
        long long x = 0;
        int highest_bit = 0;
        for (long long bit = 0; bit < 50; bit++) {
            int abit = (a >> bit) & 1;
            int bbit = (b >> bit) & 1;
            if (bbit == 1 && abit != 1) {
                highest_bit = bit;
            }
        }
        for (long long bit = 0; bit < n; bit++) {
            int abit = (a >> bit) & 1;
            int bbit = (b >> bit) & 1;
            if (abit == 1 && bbit == 1) {
                continue;
            }
            if (abit == 0 && bbit == 0) {
                x |= (1LL << bit);
                continue;
            }
        }
        for (long long bit = 0; bit < min(n, highest_bit); bit++) {
            int abit = (a >> bit) & 1;
            int bbit = (b >> bit) & 1;
            if (abit == 0 && bbit == 1) {
                x |= (1LL << bit);
            }
        }

        long long ans = ((x ^ a) % MOD) * ((x ^ b) % MOD);
        ans %= MOD;
        return ans;
    }
};
