class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        s.back() = '1';
        ones--;
        for (int i = 0; i < s.size() - 1; i++) {
            if (ones > 0) {
                ones--; 
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        return s;
    }
};
