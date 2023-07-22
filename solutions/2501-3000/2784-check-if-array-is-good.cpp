class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i < n - 2) {
                if (nums[i] != i + 1) return false;
            } else {
                if (nums[i] != n - 1) return false;
            }
        }
        return true;
    }
};
