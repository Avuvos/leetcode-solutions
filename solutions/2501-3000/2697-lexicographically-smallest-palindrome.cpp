class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (l == r) break;
            if (s[l] != s[r]) {
                char mn = min(s[l], s[r]);
                s[l] = mn;
                s[r] = mn;
            }
            l++;
            r--;
        }
        return s;
    }
};
