class Solution {
public:
    int countSubstrings(string s) {
        int n = (int) s.size();
        auto extend_pal = [&](int l, int r) {
            int ans = 0;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) break;
                l--;
                r++;
                ans++;
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += extend_pal(i, i);
            ans += extend_pal(i, i + 1);
        }
        return ans;
    }
};
