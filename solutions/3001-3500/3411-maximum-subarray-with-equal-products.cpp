class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            long long p = 1, l = 1, g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                p *= nums[j];
                if (p > l * g) break;
                if (p == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
