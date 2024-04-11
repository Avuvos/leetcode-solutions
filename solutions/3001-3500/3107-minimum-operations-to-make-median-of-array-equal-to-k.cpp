class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n / 2];
        if (med == k) return 0;
        long long cost = 0;
        if (med < k) {
            for (int i = n/2; i < n; i++) {
                if (nums[i] <= k) {
                    cost += (k - nums[i]);
                }
            }
        } else {
            for (int i = 0; i <= n / 2; i++) {
                if (nums[i] >= k) {
                    cost += (nums[i] - k);
                }
            }
        }
        return cost;
    }
};
