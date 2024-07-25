class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, before = 0;
        int n = (int) s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                before += 1;
            }
            if (s[i] == '1' && s[i + 1] == '0') {
                ans += before;
            }
        }
        return ans;
    }
};
