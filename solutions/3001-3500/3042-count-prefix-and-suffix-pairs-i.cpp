class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        auto is_suf = [&](int i, int j) -> bool {
            return words[j].substr(words[j].size() - words[i].size() , words[i].size()) == words[i];
        };
        
        auto is_pref = [&](int i, int j) -> bool {
            return words[j].substr(0, words[i].size()) == words[i];
        };
        
        auto ok = [&](int i, int j) -> bool {
            return is_pref(i, j) && is_suf(i, j);
        };
        
        int n = (int) words.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += ok(i, j);
            }
        }
        return ans;
    }
};
