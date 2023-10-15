class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = (int) s.size();
        const int inf = 1e9 + 2;
        int bestLen = inf;
        string ans;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                cnt += (s[j] - '0');
                if (cnt == k && (j - i + 1) < bestLen) {
                    bestLen = j - i + 1;
                    ans = s.substr(i, bestLen);
                } else if (cnt == k && (j - i + 1) == bestLen) {
                    ans = min(ans, s.substr(i, bestLen));
                }
            }
        }
        return ans;
    }
};
