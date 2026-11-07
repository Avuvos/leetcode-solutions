class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            if (nums[r] > maxK || nums[r] < minK) {
                l = r + 1;
                continue;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
