class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long v = nums[i];
            if (mul > 0) {
                v *= mul;
                mul--;
            }
            ans += v;
        }
        return ans;
    }
};
