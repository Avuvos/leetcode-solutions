class Solution {
public:
    
    vector<bool> primes(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return is_prime;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime = primes(right + 5);
        int prev = -1;
        int min_val = 1e9;
        vector<int> res = {-1, -1};
        for (int i = left; i <= right; i++) {
            if (!is_prime[i]) continue;
            if (prev == -1) {
                prev = i;
            } else {
                if (i - prev < min_val) {
                    min_val = i - prev;
                    res = {prev, i};
                }
                prev = i;
            }
        }
        return res;
    }
};
