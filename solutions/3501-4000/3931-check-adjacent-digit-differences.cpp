class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int p = -1;
        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            if (p != -1 && abs(p - d) > 2) {
                return false;
            }
            p = d;
        }
        return true;
    }
};
