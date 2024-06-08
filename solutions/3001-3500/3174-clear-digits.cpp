class Solution {
public:
    string clearDigits(string s) {
        int n = (int) s.size();
        int cnt = 0;
        vector<bool> alive(n, true);
        for (int i = n - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                cnt += 1;
                alive[i] = false;
            } else if (cnt > 0) {
                cnt -= 1;
                alive[i] = false;
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (alive[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};
