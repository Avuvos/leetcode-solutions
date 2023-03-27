class Solution {
public:
    vector<int> primes;
    vector<int> primesf(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    bool primeSubOperation(vector<int>& nums) {
        primesf(1001);
        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int to_sub = -1;
            for (auto &p: primes) {
                if (nums[i] - p > prev) {
                    to_sub = p;
                }
            }
            if (to_sub != -1) {
                nums[i] -= to_sub;
            }
            prev = nums[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) return false;
        }
        return true;
    }
};
