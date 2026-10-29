class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int prev = nums[0], ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                prev = nums[i];
                continue;
            }
            ans++;
        }
        return ans;
    }
};
