class Solution {
public:
    long long validSubstringCount(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> cnt(26, 0);
        for (auto &c: t) cnt[c - 'a']++;
        
        int todo = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                todo++;
            }
        }
        
        long long ans = 0;
        vector<int> cnts(26, 0);
        for (int l = 0, r = 0; r < n; r++) {
            if (++cnts[s[r] - 'a'] == cnt[s[r] - 'a']) {
                todo--;
            } 
            
            while (l <= r && todo == 0) {
                ans += (n - r);
                if (--cnts[s[l] -'a'] < cnt[s[l] - 'a']) {
                    todo++;
                }
                l++;
            }
            
        }
        return ans;
        
    }
};
