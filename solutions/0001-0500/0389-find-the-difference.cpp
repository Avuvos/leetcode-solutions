class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> cnt(26, 0);
        for (auto &c: t) {
            cnt[c - 'a']++;
        }
        for (auto &c: s) {
            cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                return char(i + 'a');
            }
        }
        return -1;
    }
};
