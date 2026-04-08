class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL), p = 1;
        long long max_sum = s;
        int n = nums.size(), ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            s -= nums[i];
            if (i + 1 < n) {
                if (p <= max_sum / nums[i + 1]) {
                    p *= nums[i + 1];
                } else {
                    break;
                }
            }
            if (s == p) {
                ans = i;
            }
            if (p > max_sum) break;
        }
        return ans;
    }
};
