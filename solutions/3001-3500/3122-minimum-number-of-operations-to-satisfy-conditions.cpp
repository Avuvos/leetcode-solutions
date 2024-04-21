class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        //dp[i][last] = min num of moves where the last column is with number last
        int dp[1001][11];
        memset(dp, -1, sizeof(dp));
        const int inf = 1e9 + 17;
        auto dfs = [&](auto dfs, int col, int prev) -> int {
            if (col >= m) {
                return 0;
            }
            if (dp[col][prev] != -1) {
                return dp[col][prev];
            }
            vector<int> count(10, 0);
            for (int i = 0; i < n; i++) {
                count[grid[i][col]]++;
            }
            int ans = inf;
            for (int c = 0; c <= 9; c++) {
                if (c == prev) continue;
                ans = min(ans, n - count[c] + dfs(dfs, col + 1, c));
            }
            return dp[col][prev] = ans;
        };
        return dfs(dfs, 0, 10);
    }
};
