class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        for (auto &c: s) {
            cnt[c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] <= 2) {
                ans += cnt[i];
                continue;
            }
            if (cnt[i] % 2 == 0) {
                ans += 2;
            } else {
                ans += 1;
            }
        }
        return ans;
    }
};
