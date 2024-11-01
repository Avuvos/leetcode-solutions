class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n <= 2) {
            return s;
        }
        string ans;
        char p1 = s[0], p2 = s[1];
        ans.push_back(p1);
        ans.push_back(p2);
        for (int i = 2; i < n; i++) {
            if (s[i] == p1 && s[i] == p2) continue;
            p1 = p2;
            p2 = s[i];
            ans.push_back(s[i]);
        }
        return ans;
    }
};
