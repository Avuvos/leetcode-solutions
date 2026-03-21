class Solution {
public:
    int countMonobit(int n) {
        if (n <= 1) {
            return n + 1;
        }
        int p = 1, ans = 1;
        while (p < n) {
            p *= 2;
            if (p - 1 <= n) {
                ans++;
            }
        }
        return ans;
    }
};
