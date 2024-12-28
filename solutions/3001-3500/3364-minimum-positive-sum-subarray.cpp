class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int best = 1e9, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r && sum > 0) {
                    best = min(best, sum);
                }
            }
        }
        return best < 1e9 ? best : -1;
    }
};
