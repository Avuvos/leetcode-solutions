class Solution {
public:
    bool is_prime(int x) {
        if (x == 1) return false;
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                return false;
            }
        }
        return true;
    }
    int largestPrime(int n) {
        int s = 0, ans = 0;
        for (int i = 2; i + s <= n; i++) {
            if (is_prime(i)) {
                s += i;
            }
            if (is_prime(s)) {
                ans = s;
            }
        }
        return ans;
    }
};
