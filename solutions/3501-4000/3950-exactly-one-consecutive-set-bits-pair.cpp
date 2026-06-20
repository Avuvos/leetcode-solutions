class Solution {
public:
    bool consecutiveSetBits(int n) {
        int p = -1, cnt = 0;
        while (n > 0) {
            int c = n % 2;
            if (c && p == c) {
                cnt++;
            }
            p = c;
            n >>= 1;
        }
        return cnt == 1;
    }
};
