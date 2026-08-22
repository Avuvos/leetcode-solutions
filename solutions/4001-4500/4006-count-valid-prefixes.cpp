class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int zeros = 0, ones = 0;
        for (auto &c: s) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
            if (abs(zeros - ones) <= 1) {
                ans++;
            }
        }
        return ans;
    }
};
