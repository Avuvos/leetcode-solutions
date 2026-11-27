class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (i > 0 && s1[i - 1] != s2[i - 1]) {
                ans.back()[0].push_back(s1[i]);
                ans.back()[1].push_back(s2[i]);
            } else {
                ans.push_back({s1.substr(i, 1), s2.substr(i, 1)});
            }
        }
        return ans;
    }
};
