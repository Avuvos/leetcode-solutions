class Solution {
public:
    vector<int> primes;
    void sieve() {
        int N = 1002;
        vector<bool> is_prime(N, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i < N; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i; j < N; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    };
    int sumOfPrimesInRange(int n) {
        if (primes.empty()) {
            sieve();
        }
        string sn = to_string(n);
        reverse(sn.begin(), sn.end());
        int r = stoi(sn);
        int mn = min(n, r), mx = max(n, r), ans = 0;
        for (auto &p: primes) {
            if (p >= mn && p <= mx) {
                ans += p;
            }
            if (p > mx) break;
        }
        return ans;
    }
};
