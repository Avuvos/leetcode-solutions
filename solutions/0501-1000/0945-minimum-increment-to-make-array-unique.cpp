class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int previous = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= previous) {
                int delta = previous - nums[i] + 1;
                nums[i] += delta;
                ans += delta;
            }
            previous = nums[i];
        }
        return ans;
    }
};
