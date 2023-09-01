class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        const int BITS = 18;
        for (int i = 0; i <= n; i++) {
            for (int bit = 0; bit < BITS; bit++) {
                if ((i >> bit) & 1) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};
