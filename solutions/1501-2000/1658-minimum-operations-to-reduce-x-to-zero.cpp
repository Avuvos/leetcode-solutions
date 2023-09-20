class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = (int) nums.size();
        int ans = n + 17, ps = 0;
        for (int i = 0; i < n; i++) {
            ps += nums[i];
            if (ps == x) {
                ans = min(ans, i + 1);
            }
        }
        int p = n - 1, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            while (p >= 0 && (sum + ps > x || p >= i)) {
                ps -= nums[p];
                p--;
            }
            if (sum + ps == x) {
                ans = min(ans, p + 1 + n - i);
            }
        }   
        return ans < n + 17 ? ans : -1;
    }
};
