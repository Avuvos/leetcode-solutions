class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9, sum = 0;
        for (int right = 0, left = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (left <= right && sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans < 1e9 ? ans : 0;
    }
};
