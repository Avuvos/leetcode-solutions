class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = max_element(nums.begin(), nums.end()) - nums.begin();
        for (auto &a: nums) {
            if (a == nums[ans]) continue;
            if (2*a > nums[ans]) return -1;
        }
        return ans;
    }
};
