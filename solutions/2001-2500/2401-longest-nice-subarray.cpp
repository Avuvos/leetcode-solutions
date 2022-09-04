class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int a = 0;
        int res = 1;
        for (int right = 0; right < nums.size(); ++right) {
            while ((a & nums[right]) > 0) {
                a ^= nums[left];
                left++;
            }
            a |= nums[right];
            res = max(res, right - left + 1);
        }
        return res;
    }
};
