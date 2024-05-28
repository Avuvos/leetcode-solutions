class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = (int) s.size();
        int ans = 0;
        int cost = 0;
        for (int r = 0, l = 0; r < n; r++) {
            cost += abs((t[r] - '0') - (s[r] - '0'));
            while (cost > maxCost) {
                cost -= abs((t[l] - '0') - (s[l] - '0'));
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
