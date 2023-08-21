class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = (int) s.size();
        if (n == 1) return false;
        for (int i = 1; i <= n/2; i++) {
            if (n % i) continue;
            string pattern = s.substr(0, i);
            string current;
            for (int j = 0; j < n / i; j++) {
                current += pattern;
            }
            if (current == s) {
                return true;
            }
        }
        return false;
    }
};
