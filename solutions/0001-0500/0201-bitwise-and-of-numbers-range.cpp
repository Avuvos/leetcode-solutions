class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int lb = (left >> bit) & 1;
            int rb = (right >> bit) & 1;
            if (rb && !lb) break;
            int l = left, r = right, ok = 1;
            while (l <= r) {
                int m = l + (r - l)/2;
                if ((m >> bit) & 1) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans += (1 << bit);
            }
        }
        return ans;
    }
};
