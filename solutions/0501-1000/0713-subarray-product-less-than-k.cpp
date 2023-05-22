class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, prod = 1;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                prod /= nums[l++];
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
