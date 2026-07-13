class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        auto get_range = [&](int x) -> int {
            int mn = 10, mx = -1;
            while (x > 0) {
                int d = x % 10;
                mn = min(mn, d);
                mx = max(mx, d);
                x /= 10;
            }
            return mx - mn;
        };
        int ans = 0, mx = -1;
        for (auto &x: nums) {
            int dr = get_range(x);
            if (dr > mx) {
                ans = x;
                mx = dr;
            } else if (dr == mx) {
                ans += x;
            }
        }
        return ans;
    }
};
