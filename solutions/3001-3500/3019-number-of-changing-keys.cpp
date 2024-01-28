class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            char p = tolower(s[i - 1]);
            char c = tolower(s[i]);
            if (c != p) {
                ans++;
            }
        }
        return ans;
    }
};
