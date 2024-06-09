class Solution {
public:
    int numberOfChild(int n, int k) {
        k %= (2 * n - 2);
        if (k <= n - 1) {
            return k;
        }
        k -= (n - 1);
        return (n - 1) - k;
    }
};
