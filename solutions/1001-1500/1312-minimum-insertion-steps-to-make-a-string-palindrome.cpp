class Solution {
public:
    int minInsertions(string s) {
        int n = (int) s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int l, int r) {
            if (l >= r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            if (s[l] == s[r]) {
                return dfs(l + 1, r - 1);
            }
            dp[l][r] = 1 + min(dfs(l + 1, r), dfs(l, r - 1));
            return dp[l][r];
        };
        return dfs(0, n - 1);
    }
};
