class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) {
            return "none";
        }
        set<int> s(nums.begin(), nums.end());
        if (s.size() == 1) {
            return "equilateral";
        }
        if (s.size() == 2) {
            return "isosceles";
        }
        return "scalene";
    }
};
