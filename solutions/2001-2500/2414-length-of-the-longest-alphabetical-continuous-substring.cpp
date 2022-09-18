class Solution {
public:
    int longestContinuousSubstring(string s) {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int n = s.size();
        int res = 1, streak = 1;
        //cout << "-------" << '\n';
        for (int i = 1; i < n; i++) {
            if ((s[i] - 'a' - (s[i - 1] - 'a') == 1)) {
                //cout << "Good " << i << '\n';
                streak++;
                res = max(res, streak);
            }
            else {
                streak = 1;
            }
        }
        return max(res, streak);
    }
};
