class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = 0, mx = 0;
        for (int i = nums.size() - k - 1; i >= 0; i--) {
            mx = max(mx, nums[i + k]);
            ans = max(ans, nums[i] + mx);
        }
        return ans;
    }
};
