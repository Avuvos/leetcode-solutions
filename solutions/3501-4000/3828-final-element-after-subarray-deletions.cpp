class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        int ans = max(nums[0], nums[n - 1]);
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(nums[i], nums[n - 1]));
            ans = max(ans, min(nums[i], nums[0]));
        }
        return ans;
    }
};
