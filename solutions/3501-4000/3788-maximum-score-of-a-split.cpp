class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size(), mn = nums[n - 1];
        long long s = accumulate(nums.begin(), nums.end(), 0LL) - nums[n - 1], ans = -1e18;
        for (int i = n - 2; i >= 0; i--) {
            ans = max(ans, s - mn);
            s -= nums[i];
            mn = min(mn, nums[i]);
        }
        return ans;
    }
};
