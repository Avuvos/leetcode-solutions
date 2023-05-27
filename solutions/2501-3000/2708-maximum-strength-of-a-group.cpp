class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = -100000000000;
        int n = (int) nums.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            long long cur = 1;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    cur *= nums[i];
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
