class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int mn = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[mn]) {
                    mn = i;
                }
            }
            nums[mn] *= multiplier;
        }
        return nums;
    }
};
