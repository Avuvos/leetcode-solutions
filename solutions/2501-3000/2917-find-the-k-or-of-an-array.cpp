class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        for (auto x: nums) {
            for (int bit = 0; bit < 31; bit++) {
                if ((x >> bit) & 1) {
                    cnt[bit]++;
                }
            }
        }
        int ans = 0;
        for (int bit = 0; bit < 31; bit++) {
            if (cnt[bit] >= k) {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};
