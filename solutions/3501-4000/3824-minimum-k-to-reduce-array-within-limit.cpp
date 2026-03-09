class Solution {
public:
    int minimumK(vector<int>& nums) {
        int l = 1, r = 1e5 + 2, ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long s = 0;
            for (auto &x: nums) {
                s += (x + m - 1) / m;
            }
            if (s <= 1LL * m * m) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
