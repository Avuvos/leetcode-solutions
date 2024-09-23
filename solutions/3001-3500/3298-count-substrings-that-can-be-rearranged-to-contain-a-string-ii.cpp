class Solution {
public:
    long long validSubstringCount(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<int> counts_t(26, 0);
        for (auto &c: t) {
            counts_t[c - 'a']++;
        } 
        
        int todo = 0;
        for (int i = 0; i < 26; i++) {
            todo += (counts_t[i] > 0);
        }
        
        long long ans = 0;
        vector<int> counts_s(26, 0);
        for (int l = 0, r = 0; r < n; r++) {
            if (++counts_s[s[r] - 'a'] == counts_t[s[r] - 'a']) {
                todo--;
            } 
            
            while (l <= r && todo == 0) {
                ans += (n - r);
                if (--counts_s[s[l] -'a'] < counts_t[s[l] - 'a']) {
                    todo++;
                }
                l++;
            }
            
        }
        return ans;
    }
};
