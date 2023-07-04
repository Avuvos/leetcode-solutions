class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        for (int l = 0; l < n; l++) {
            if (nums[l] & 1 || nums[l] > threshold) continue;
            if (nums[l] <= threshold) ans = max(ans, 1);
            for (int r = l + 1; r < n; r++) {
                if (nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ans = max(ans, r - l + 1);
                    continue;
                }
                break;
            }
        }
        return ans;
    }
};
