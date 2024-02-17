class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> cnt(26, 0);
        for (auto &c: s) cnt[c - 'a']++;
        int mx = *max_element(cnt.begin(), cnt.end());
        string ans;
        int n = (int) s.size();
        vector<bool> seen(n, false);
        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            if (cnt[idx] == mx && !seen[idx]) {
                ans.push_back(s[i]);
            }
            seen[idx] = true;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
