class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] <= nums[j - 1]) break;
                cur += 1;
            }
            ans = max(ans, cur);
            cur = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] >= nums[j - 1]) break;
                cur += 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
