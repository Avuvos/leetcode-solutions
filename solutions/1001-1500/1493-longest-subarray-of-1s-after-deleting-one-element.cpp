class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> left(n, 0);
        vector<int> right(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                left[i] = left[max(0, i - 1)] + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                right[i] = right[i + 1] + 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) ans = max(ans, right[i + 1]);
            else ans = max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
};
