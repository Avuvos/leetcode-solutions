class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (goal.size() != s.size()) return false;
        int idx1 = -1, idx2 = -1;
        bool hasSame = false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == goal[i]) {
                cnt[s[i] - 'a']++;
                if (cnt[s[i] - 'a'] >= 2) hasSame = true;
                continue;
            }
            if (idx1 == -1) {
                idx1 = i;
            } else if (idx2 == -1) {
                idx2 = i;
            } else {
                return false;
            }
        }
        
        if (idx1 == -1 && idx2 == -1) {
            return hasSame;
        }
        
        if (idx1 == -1 || idx2 == -1) {
            return false;
        }
        
        if (s[idx1] == goal[idx2] && s[idx2] == goal[idx1]) {
            return true;
        }
        return false;
    }
};
