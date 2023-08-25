class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == s1.size() && j == s2.size()) {
                return 1;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int ans = 0;
            if (i < s1.size() && s1[i] == s3[i + j]) {
                ans |= dfs(i + 1, j);
            }
            if (j < s2.size() && s2[j] == s3[i + j]) {
                ans |= dfs(i, j + 1);
            }
            return dp[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
