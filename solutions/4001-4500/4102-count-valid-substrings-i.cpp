class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            if (r >= 2 && s.substr(r - 2, 3) == "abc") {
                l = r - 1;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
