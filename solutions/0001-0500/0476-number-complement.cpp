class Solution {
public:
    int findComplement(int num) {
        int msb = 31 - __builtin_clz(num);
        int ans = 0;
        for (int bit = msb - 1; bit >= 0; bit--) {
            if (((num >> bit) & 1) == 0) {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};
