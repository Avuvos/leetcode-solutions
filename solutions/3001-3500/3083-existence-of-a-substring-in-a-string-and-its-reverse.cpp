class Solution {
public:
    bool isSubstringPresent(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        for (int i = 0; i + 1 < s.size(); i++) {
            string cur = s.substr(i, 2);
            for (int j = 0; j + 1 < t.size(); j++) {
                string tmp = t.substr(j, 2);
                if (cur == tmp) {
                    return true;
                }
            }
        }
        return false;
    }
};
