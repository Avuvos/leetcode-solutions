class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cnt(26, 0);
        vector<int> sizes;
        for (auto &s: words) {
            for (auto &c: s) {
                cnt[c - 'a']++;
            }
            sizes.push_back(s.size());
        }
        int pairs = 0;
        for (int i = 0; i < 26; i++) {
            pairs += cnt[i] / 2;
        }
        sort(sizes.begin(), sizes.end());
        int ans = 0;
        for (int sz: sizes) {
            int need = sz / 2;
            pairs -= need;
            if (pairs >= 0) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};
