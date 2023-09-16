class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        int n = (int) nums.size();
        for (int i = 0; i <= n; i++) {
            vector<int> next_nums(n);
            for (int i = 0; i < n; i++) {
                next_nums[i] = nums[(i - 1 + n) % n];
            }
            if (is_sorted(next_nums.begin(), next_nums.end())) {
                return i + 1;
            }
            nums = next_nums;
        }
        return -1;
    }
};
