class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++) {
            if ((c >> bit) & 1) {
                if (((a >> bit) & 1) || ((b >> bit) & 1)) continue;
                ans++;
            } else {
                if ((a >> bit) & 1) ans++;
                if ((b >> bit) & 1) ans++;
            }
        }
        return ans;
    }
};
