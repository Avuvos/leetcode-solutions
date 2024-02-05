class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int) s.size();
        map<int, int> cnt;
        set<int> st;
        for (auto &c: t) {
            cnt[c]++;
            st.insert(c);
        }
        int required = cnt.size();
        int ans = n + 1, ansL = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (--cnt[s[r]] == 0 && st.find(s[r]) != st.end()) {
                required--;
            }
            if (required == 0 && r - l + 1 < ans) {
                ans = r - l + 1;
                ansL = l;
            }
            while (l < r && required == 0) {
                if (++cnt[s[l]] == 1 && st.find(s[l]) != st.end()) {
                    required++;
                }
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    ansL = l;
                }
                l++;   
            }
            if (required == 0 && r - l + 1 < ans) {
                ans = r - l + 1;
                ansL = l;
            }
            
        }
        
        if (ans > n) {
            return "";
        }
        return s.substr(ansL, ans);
    }
};
