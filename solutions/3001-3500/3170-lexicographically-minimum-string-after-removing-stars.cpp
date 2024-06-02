class Solution {
public:
    string clearStars(string s) {
        int n = (int) s.size();
        vector<bool> dead(n, false);
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!pos[j].empty()) {
                        dead[pos[j].back()] = true;
                        pos[j].pop_back();
                        break;
                    }
                }
                dead[i] = true;
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (!dead[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
