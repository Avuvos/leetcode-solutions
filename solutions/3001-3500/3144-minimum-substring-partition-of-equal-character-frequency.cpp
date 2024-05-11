class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = (int) s.size();
        const int INF = 1e9 + 2;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        
        auto balanced = [&](vector<int> &cnt) -> bool {
            int mx = *max_element(cnt.begin(), cnt.end());
            return all_of(cnt.begin(), cnt.end(), [&](int x) {return (x == mx || x == 0);});
        };
        
        for (int i = 1; i <= n; i++) {
            vector<int> cnt(26, 0);
            cnt[s[i - 1] - 'a']++;
            for (int j = i - 1; j >= 0; j--) {
                if (balanced(cnt)) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
                if (j > 0) cnt[s[j - 1] - 'a']++;
            }
        }
        return dp[n];
    }
};
