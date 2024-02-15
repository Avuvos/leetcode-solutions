class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0, ans = -1;
        for (int i = 0; i < 2; i++) {
            sum += nums[i];
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] < sum) {
                ans = max(ans, sum + nums[i]);
            }
            sum += nums[i];
        }
        return ans;
    }
};
