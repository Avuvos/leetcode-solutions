class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int ans = n + 17;
        for (int l = 0; l < n; l++) {
            int val = 0;
            for (int r = l; r < n; r++) {
                val |= nums[r];
                if (val >= k) {
                    ans = min(ans, r - l + 1);
                }
            }
        }
        return ans <= n ? ans : -1;
    }
};
