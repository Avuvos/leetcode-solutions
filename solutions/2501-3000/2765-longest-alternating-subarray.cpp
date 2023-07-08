class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = (int) nums.size(), ans = -1;
        for (int l = 0; l + 1 < n; l++) {
            int prev = nums[l + 1] - nums[l];
            if (prev != 1) continue;
            ans = max(ans, 2);
            for (int r = l + 2; r < n; r++) {
                if (nums[r] - nums[r - 1] != -prev) break;
                ans = max(ans, r - l + 1);
                prev = nums[r] - nums[r - 1];
            }
        }
        return ans;
    }
};
