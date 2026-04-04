class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size(), mx = 1e5, mn = -1e5;
        sort(nums.begin(), nums.end());
        long long ans = max(1LL * nums[0] * nums[1] * nums[n-1], 1LL * nums[n-1] * nums[n-2] * nums[n-3]);
        ans = max(ans, 1LL * nums[0] * nums[1] * mx);
        ans = max(ans, 1LL * nums[0] * nums[1] * mn);
        ans = max(ans, 1LL * nums[n - 1] * nums[n - 2] * mx);
        ans = max(ans, 1LL * nums[n - 1] * nums[n - 2] * mn);
        ans = max(ans, 1LL * nums[0] * nums[n - 1] * mn);
        ans = max(ans, 1LL * nums[0] * nums[n - 1] * mx);
        return ans;
    }
};
