class Solution {
public:
    int maximumLength(string s) {
        int n = (int) s.size();
        int ans = -1;
        for (char c = 'a'; c <= 'z'; c++) {
            int left = 1, right = n + 1;
            int streak = 0, cnt = 0;
            vector<long long> ps(n + 2, 0);
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    streak++;
                } else {
                    streak = 0;
                }
                if (streak > 0) {
                    ps[1]++;
                    ps[streak + 1]--;
                }
            }
            for (int i = 1; i <= n; i++) {
                ps[i] += ps[i - 1];
                if (ps[i] >= 3) {
                    ans = max(ans, i);
                }
            }
        }
        return ans;
    }
};
