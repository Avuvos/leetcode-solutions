class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = (int) s.size();
        vector<int> pos(26, -1);
        vector<bool> stacked(26, false);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
        }
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (stacked[s[i] - 'a']) continue;
            while (!stk.empty() && s[i] < s[stk.back()] && pos[s[stk.back()] - 'a'] > i) {
                stacked[s[stk.back()] - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(i);
            stacked[s[i] - 'a'] = true;
        }
        string ans;
        for (int i = 0; i < stk.size(); i++) {
            ans += s[stk[i]];
        }
        return ans;
    }
};
