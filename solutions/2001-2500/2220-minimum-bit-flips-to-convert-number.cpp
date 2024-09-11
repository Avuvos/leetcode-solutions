class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for (int bit = 0; bit < 30; bit++) {
            if (((start >> bit) & 1) ^ ((goal >> bit) & 1)) {
                ans++;
            }
        }
        return ans;
    }
};
