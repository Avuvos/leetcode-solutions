class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int x = nums[0];
        for (auto &a: nums) x &= a;
        if (x > 0) {
            return 1;
        }
        int n = (int) nums.size();
        vector<int> suf(n + 1);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] & nums[i];
        }
        int ans = 0;
        int cur = -1;
        for (int i = 0; i < n; i++) {
            cur = (cur == -1 ? nums[i] : cur & nums[i]);
            if (cur == x && (i == n - 1 || suf[i + 1] == x)) {
                ans++;
                cur = -1;
            }
        }
        return ans;
    }
};
