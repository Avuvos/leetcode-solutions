class Solution {
public:
    int pivotInteger(int n) {
        int tot = n * (n + 1) / 2;
        for (int x = 1; x <= n; x++) {
            int l = x * (x + 1) / 2;
            int r = tot - l + x;
            if (l == r) {
                return x;
            }
        }
        return -1;
    }
};
