class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vals;
        for (auto &x: nums) {
            if (x >= 0) {
                vals.push_back(x);
            }
        }
        int sz = vals.size();
        if (sz == 0) {
            return nums;
        }
        k %= sz;
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = vals[(j + k) % sz];
                j++;
            }
        }
        return nums;
    }
};
