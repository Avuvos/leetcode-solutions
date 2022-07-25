class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int e = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (s >= nums.size() || nums[s] != target) {
            return {-1, -1};
        }
        return {s, e - 1};
    }
};
