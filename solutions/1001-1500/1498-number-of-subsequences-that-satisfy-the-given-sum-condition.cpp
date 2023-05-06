class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        long long ans = 0;
        
        
        auto expo = [&](long long a, long long b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) {
                    res *= a;
                    res %= MOD;
                }
                a *= a;
                a %= MOD;
                b >>= 1;
            }
            return res;
        };
        
        for (int i = 0; i < nums.size(); i++) {
            int cur = target - nums[i];
            int index = upper_bound(nums.begin() + i, nums.end(), cur) - nums.begin() - 1;
            if (index < i) continue;
            ans += (expo(2, index - i));
            ans %= MOD;
        }
        return ans;
    }
};
