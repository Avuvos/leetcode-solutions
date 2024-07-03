class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = (int) nums.size();
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 2e9+2;
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 3; j++) {
                if (i + j != 3) continue;
                ans = min(ans, nums[n - 1 - j] - nums[i]);
            }
        }
        return ans;
    }
};
