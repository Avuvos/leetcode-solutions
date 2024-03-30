class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int ans = n + 17;
        int val = 0;
        vector<int> cnt(30, 0);
        for (int l = 0, r = 0; r < n; r++) {
            val |= (nums[r]);
            for (int bit = 0; bit < 30; bit++) {
                if ((nums[r] >> bit) & 1) {
                    cnt[bit] += 1;
                }
            }
            while (l < r && val >= k) {
                ans = min(ans, r - l + 1);
                for (int bit = 0; bit < 30; bit++) {
                    if ((nums[l] >> bit) & 1) {
                        cnt[bit] -= 1;
                        if (cnt[bit] == 0) {
                            val -= (1 << bit);
                        }
                    }
                }
                l++;
            }
            if (val >= k) ans = min(ans, r - l + 1);
        }
        return ans <= n ? ans : -1;
    }
};
