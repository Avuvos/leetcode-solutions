class Solution {
public:
    long long flowerGame(int n, int m) {
        int en = n / 2, on = (n + 1) / 2;
        int em = m / 2, om = (m + 1) / 2;
        return 1LL * en * om + 1LL * on * em;
    }
};
