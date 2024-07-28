class Solution {
public:
    
    bool is_prime(int x)  {
        if (x == 1) {
            return false;
        }
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                return false;
            }
        }
        return true;
    }
    
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        for (int x = 1; x <= r; x++) {
            long long y = 1LL * x * x;
            if (y > r) break;
            if (y >= l && is_prime(x)) {
                ans -= 1;
            }
        }
        return ans;
    }
};
