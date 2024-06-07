class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 2, vector<int>(m, -1));
        auto dfs = [&](auto dfs, int i, int j) -> int {
            if (j >= m && i >= n) {
                return 1;
            }
            if (j >= m) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            bool match = i < n && (s[i] == p[j] || p[j] == '.');
            if (j + 1 < m && p[j + 1] == '*') {
                return dp[i][j] = dfs(dfs, i, j + 2) || (match && dfs(dfs, i + 1, j));
            }
            return dp[i][j] = match && dfs(dfs, i + 1, j + 1);
        };
        return dfs(dfs, 0, 0);
    }
};
