class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= ( (nums[i]|nums[i]) & nums[i]);
        }
        return res;
    }
};
