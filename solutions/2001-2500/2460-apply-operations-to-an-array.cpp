class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        vector<int> res;
        int cnt_zeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt_zeroes++;
            else res.push_back(nums[i]);
        }
        
        for (int i = 0; i < cnt_zeroes; i++) {
            res.push_back(0);
        }
        
        return res;
    }
};
