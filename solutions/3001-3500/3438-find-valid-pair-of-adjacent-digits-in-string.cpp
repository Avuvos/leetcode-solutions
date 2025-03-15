class Solution {
public:
    string findValidPair(string s) {
        vector<int> cnt(10, 0);
        for (auto &c: s) cnt[c - '0']++;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] - '0' == cnt[s[i] - '0'] && s[i + 1] - '0' == cnt[s[i + 1] - '0']) {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};
