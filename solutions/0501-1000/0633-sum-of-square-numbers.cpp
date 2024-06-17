class Solution {
public:
    bool judgeSquareSum(int c) {
        auto is_sqrt = [&](int x) -> bool {
            int z = (int) sqrt(x);
            return z * z == x;
        };
        
        for (int a = 0; 1LL * a * a <= c; a++) {
            int b = c - 1LL * a * a;
            if (is_sqrt(b)) {
                return true;
            }
        }
        
        return false;
        
        
    }
};
