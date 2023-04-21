class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                int c = a*a + b*b;
                int sq = (int) sqrt(c);
                if (sq <= n && sq*sq == c) ans++;
            }
        }
        return ans * 2;
    }
};
