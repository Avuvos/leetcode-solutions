class Solution {
public:
    long long nthSmallest(long long n, int k) {

        auto choose = [&](long long n, long long k) -> long long {
            if (k > n || k < 0) return 0;
            long long count = 1;
            for (int i = 1; i <= k; i++) {
                count = count * (n - k + i) / i;
            }
            return count;
        };

        long long ans = 0;
        for (int bit = 49; bit >= 0; bit--) {
            if (k == 0) break;
            long long count = choose(bit, k);
            if (count < n) {
                ans |= (1LL << bit);
                k--;
                n -= count;
            }
        }
        return ans;
    }
};
