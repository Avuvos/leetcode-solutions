class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); i++) {
            inc = inc && (nums[i] >= nums[i - 1]);
            dec = dec && (nums[i] <= nums[i - 1]);
        }
        return dec || inc;
    }
};
