class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int m = abs(n);
        while (m > 0) {
            if (m & 1) {
                res *= x;
            }
            x *= x;
            m >>= 1;
        }
        return n >= 0 ? res : 1/res;
    }
};
