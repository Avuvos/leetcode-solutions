class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> a(n, 1);
        while (k--) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                long long next_sum = (sum + a[i]) % MOD;
                a[i] = (a[i] + sum) % MOD;
                sum = next_sum % MOD;
            }
        }
        return a.back();
    }
};
