class Solution {
public:
    bool completePrime(int num) {
        
        auto is_prime = [&](int x) -> bool {
            if (x == 1) return false;
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    return false;
                }
            }
            return true;
        };

        vector<int> nums;
        long long p = 1;
        int x = 0;
        while (num > 0) {
            nums.push_back(num);
            x += p * (num % 10);
            nums.push_back(x);
            p *= 10;
            num /= 10;
        }
        return all_of(nums.begin(), nums.end(), is_prime);
    }
};
