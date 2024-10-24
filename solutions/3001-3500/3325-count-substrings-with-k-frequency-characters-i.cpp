class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            bool ok = false;
            for (int j = i; j < n; j++) {
                if (++cnt[s[j] - 'a'] >= k) {
                    ok = true;
                }
                ans += ok;
            }
        }
        return ans;
    }
};
