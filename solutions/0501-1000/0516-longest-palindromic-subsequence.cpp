class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j] ans for string starting from i ending at j?
        //dp[i][i] = 1 for every i is the base case
        //dp[i][j] = s[i]==s[j] + dp[i + 1][j - 1]
        //else, dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        int n = s.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        function <int(int, int)> dfs = [&](int l, int r) {
            if (l > r) return 0;
            if (l == r) return 1;
            if (dp[l][r] != -1) return dp[l][r];
            int ans = 0;
            if (s[l] == s[r]) ans = 2 + dfs(l + 1, r - 1);
            ans = max(ans, dfs(l + 1, r));
            ans = max(ans, dfs(l, r - 1));
            dp[l][r] = ans;
            return ans;
        };
        return dfs(0, n - 1);
    }
};
