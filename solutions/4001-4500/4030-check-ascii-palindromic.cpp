class Solution {
public:
    bool isPalindromic(string s) {
        string res;
        for (auto &c: s) {
            int x = (int) c;
            for (int b = 0; b < 8; b++) {
                int c = (x >> b) & 1;
                res += (c == 1 ? '1' : '0');
            }
        }
        string r = res;
        reverse(r.begin(), r.end());
        return res == r;
    }
};
