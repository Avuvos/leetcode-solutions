class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> ok(26, false);
        for (auto &c: allowed) ok[c - 'a'] = true;
        int ans = 0;
        for (auto &w: words) {
            ans += all_of(w.begin(), w.end(), [&](char c) {
                return ok[c - 'a'];
            });
        }
        return ans;
    }
};
