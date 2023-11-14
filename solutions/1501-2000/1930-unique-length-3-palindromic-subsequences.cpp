class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        
        auto check = [&](int a, int b) {
            if (pos[a].empty() || pos[b].empty()) return false;
            auto it = lower_bound(pos[b].begin(), pos[b].end(), pos[a][0] + 1);
            return it != pos[b].end() && *it < pos[a].back();
        };
        
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                ans += check(c - 'a', d - 'a');
            }
        }
        return ans;
    }
};
