class Solution {
public:
    long long minEnd(int n, int x) {
        int msb = 31 - __builtin_clz(x);
        vector<int> spots;
        for (int bit = msb; bit >= 0; bit--) {
            if (((x >> bit) & 1) == 0) {
                spots.push_back(bit);
            }
        }
        for (int bit = msb + 1; bit < 60; bit++) {
            spots.push_back(bit);
        }
        sort(spots.rbegin(), spots.rend());
        int m = (int) spots.size();
        n -= 1;
        long long ans = x;
        for (int i = 0; i < m; i++) {
            long long rem = (1LL << (m - i - 1));
            if (rem > n) continue;
            n -= rem;
            ans |= (1LL << spots[i]);
        }
        return ans;
    }
};
