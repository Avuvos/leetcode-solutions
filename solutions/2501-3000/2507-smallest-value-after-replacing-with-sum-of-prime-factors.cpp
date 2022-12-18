class Solution {
public:
    
    
    
    int smallestValue(int n) {
        vector<bool> is_prime(n + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
        
        /*
        vector<int> primes = {2};
        for (int num = 3; num <= n/2 + 3; num++) {
            bool ok = true;
            for (auto &p: primes) {
                if (num % p == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                primes.push_back(num);
            }
            ok = true;
        }
        */
        
        bool change = true;
        bool div = true;
        while (change) {
            int next_n = 0;
            int tmp = n;
            for (auto &p: primes) {
                while (n % p == 0 ) {
                    n /= p;
                    next_n += p;
                }
            }
            if (next_n == tmp) change = false;
            n = next_n;
        }
        return n;
        
        
    }
};
