class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        const int inf = 1e9 + 2;
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        vector<long long> suffix(m + 1, -inf), prefix(m + 1, -inf);
        for (int i = 0; i < m; i++) {
            dp[0][i] = points[0][i];
            prefix[i + 1] = max(prefix[i], dp[0][i] + i);
        }
        for (int i = m - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], dp[0][i] - i);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(suffix[j] + j, prefix[j + 1] - j);
            }
            prefix[0] = -inf;
            for (int j = 0; j < m; j++) {
                prefix[j + 1] = max(prefix[j], dp[i][j] + j);
            }
            suffix[m] = -inf;
            for (int j = m - 1; j >= 0; j--) {
                suffix[j] = max(suffix[j + 1], dp[i][j] - j);
            }
        }

        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
