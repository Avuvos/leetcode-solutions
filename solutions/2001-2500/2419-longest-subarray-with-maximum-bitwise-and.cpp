class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int cur = (1 << 30) - 1;
        int ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            cur &= nums[r];
            if (cur != mx) {
                l = r;
                cur = nums[r];
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
