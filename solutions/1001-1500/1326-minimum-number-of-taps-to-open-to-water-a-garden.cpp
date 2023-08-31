class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int s = max(0, i - ranges[i]);
            int e = min(n, i + ranges[i]);
            for (int j = s; j <= e; j++) {
                dp[e] = min(dp[e], 1 + dp[j]);
            }
        }
        return dp[n] < INF ? dp[n] : -1;
    }
};
