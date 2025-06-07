class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n > m) swap(n, m);
        // m >= n
        if (m <= k) return 0;
        if (m - 1 <= k) return m - 1;
        return 1LL * k * (m - k);
    }
};
