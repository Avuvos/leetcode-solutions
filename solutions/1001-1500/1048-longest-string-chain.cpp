class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        
        auto is_pred = [&](string &s, string &t) {
            if (s.size() + 1 != t.size()) return false;
            for (int i = 0; i <= s.size(); i++) {
                if (s.substr(0, i) == t.substr(0, i) && s.substr(i) == t.substr(i + 1)) {
                    return true;
                }
            }
            return false;
        };
        
        int n = (int) words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (abs(int(words[j].size() - words[i].size())) >= 2) break;
                if (is_pred(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
