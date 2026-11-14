class Solution {
public:
    int calculateScore(int a, int b) {
        
        auto get = [&](int x) -> int {
            int cnt = 0;
            while (x > 0) {
                cnt += (x & 1);
                x >>= 1;
            }
            return cnt;
        };

        int ca = get(a), cb = get(b);
        return ca >= cb ? ca * cb : cb / ca;
    }
};
