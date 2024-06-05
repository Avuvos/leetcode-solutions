class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 10000);
        for (auto &w: words) {
            vector<int> cur(26, 0);
            for (auto &c: w) {
                cur[c - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], cur[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < cnt[i]; k++) {
                ans.push_back(string(1, (char) ('a' + i)));
            }
        }
        return ans;
    }
};
