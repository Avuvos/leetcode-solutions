class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if (n == 1) {
            return s1 == s2 ? 0 : s1[0] == '0' ? 1 : -1;
        }
        int ans = 0, len = 0, i = 0;
        while (i < n) {
            while (i < n && s1[i] == '1' && s2[i] == '0') {
                len++;
                i++;
            }
            ans += 3 * ((len + 1) / 2) - len;
            len = 0;
            if (i < n && s1[i] == '0' && s2[i] == '1') {
                ans++;
            }
            i++;
        }
        return ans;
    }
};
