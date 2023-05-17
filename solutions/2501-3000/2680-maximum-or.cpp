class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int bits[62] = {};
        for (auto &x: nums) {
            for (long long bit = 0; bit < 31; bit++) {
                if ((x >> bit) & 1) bits[bit]++;
            }
        }
        long long ans = 0;
        for (auto &x: nums) {
            long long new_x = (long long)x * (1LL << (long long)k);
            long long mask = 0;
            for (long long bit = 0; bit < 45; bit++) {
                if (((long long)x >> bit) & 1) {
                    bits[bit]--;
                }
                if ((new_x >> bit) & 1) {
                    bits[bit]++;
                }
                if (bits[bit] > 0) {
                    mask |= (1LL << bit);
                }
                if (((long long)x >> bit) & 1) {
                    bits[bit]++;
                }
                if ((new_x >> bit) & 1) {
                    bits[bit]--;
                }
            }
            ans = max(mask, ans);
        }
        return ans;
                       
    }
};
