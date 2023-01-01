class Solution {
public:
    
    vector<int> primes2(int n) {
        vector<int> is_prime(n + 1, -1);
        is_prime[0] = is_prime[1] = -1;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i] == -1) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = i;
            }
        }
        return is_prime;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        vector<int> is_prime = primes2(1001);
        for (auto num: nums) {
            if (num == 1) continue;
            
            if (is_prime[num] == -1) {
                ans.insert(num);
                continue;
            }
            
            while (is_prime[num] != -1) {
                ans.insert(is_prime[num]);
                num /= is_prime[num];
            }
            if (num > 1) ans.insert(num);
        }
        return ans.size();
        
    }
};
