class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> prime(n + 1, true);
        for (int p = 2; p*p <= n; p++) {
            if (prime[p]) {
                for (int j = p*p; j < n; j += p) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (prime[i]) ans++;
        }
        return ans;
    }
};
