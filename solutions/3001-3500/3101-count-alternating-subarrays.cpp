class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            if (r > 0 && nums[r] == nums[r - 1]) {
                l = r;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
