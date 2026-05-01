class Solution {
public:
    const static int N = 2e5;
    bool sieve[N + 1];
    vector<int> primes;
    int minOperations(vector<int>& nums) {
        if (primes.size() == 0) {
            for (int i = 2; i < N; i++) {
                if (!sieve[i]) {
                    sieve[i] = true;
                    primes.push_back(i);
                    for (int j = i; j < N; j += i) {
                        sieve[j] = true;
                    }
                }
            }
        }

        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(primes.begin(), primes.end(), nums[i]);
            if (i % 2 == 0) {
                ans += (*it - nums[i]);
            } else {
                if (*it == nums[i]) ans += (nums[i] == 2 ? 2 : 1);
            }
        }
        return ans;
    }
};
