class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size(), p = 0;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[p] || i == n - 1) {
                ans += 1LL * (i - p) * nums[p];
                p = i;
            }
        }
        return ans;
    }
};
