class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> forb;
        for (auto &s: forbidden) forb.insert(s);
        int n = (int) word.size();
        int ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            for (int j = r; j >= max(0, r - 10); j--) {
                if (forb.find(word.substr(j, r - j + 1)) != forb.end()) {
                    l = max(l, j + 1);
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
