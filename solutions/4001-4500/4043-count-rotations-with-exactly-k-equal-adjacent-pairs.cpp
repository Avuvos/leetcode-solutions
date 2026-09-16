class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), count = 0;
        string t = s + s;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            }
        }
        int ans = (count == k ? 1 : 0);
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                count--;
            }
            if (t[i + n - 1] == t[i + n]) {
                count++;
            }
            if (count == k) {
                ans++;
            }
        }
        return ans;
    }
};
