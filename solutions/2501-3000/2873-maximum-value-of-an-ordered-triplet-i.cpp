class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> sf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            sf[i] = max(nums[i], sf[i + 1]);
        }
        int curMax = max(nums[1], nums[0]), curMin = nums[1];
        long long ans = 0;
        for (int i = 2; i < n; i++) {
            ans = max(ans, 1LL * (curMax - curMin) * sf[i]);
            if (nums[i] > curMax) {
                curMax = nums[i];
                curMin = nums[i];
            } else if (nums[i] < curMin) {
                curMin = nums[i];
            }
        }
        return ans;
    }
};
