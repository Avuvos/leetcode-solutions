class Solution {
public:
    long long safe_pow(long long x, int k) {
        long long y = 1;
        while (k) {
            y *= x;
            if (y > 1e9) {
                return -1;
            }
            k--;
        }
        return y;
    }

    int countKthRoots(int l, int r, int k) {
        if (k == 1) {
            return r - l + 1;
        }
        int ans = 0;
        for (int x = 0; 1LL * x * x <= r; x++) {
            long long y = safe_pow(x, k);
            if (y >= l && y <= r) {
                ans++;
            }
        }
        return ans;
    }
};
