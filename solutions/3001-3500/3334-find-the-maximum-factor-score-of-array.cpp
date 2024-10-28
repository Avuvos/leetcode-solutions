class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long n = nums.size(), ans = 0, g = 0, l = nums[0];
        if (n == 1) return nums[0] * nums[0];
        for (auto &x: nums) {
            g = gcd(g, x);
            l = lcm(l, x);
        }
        ans = g * l;
        for (int i = 0; i < n; i++) {
            g = 0, l = (i == 0 ? nums[1] : nums[0]);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);
            }
            ans = max(ans, l * g);
        }
        return ans;
        
    }
};
