class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0, p = 1;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                res += p * d;
                p *= 10;
            }
            n /= 10;
        }
        return res;
    }
};
