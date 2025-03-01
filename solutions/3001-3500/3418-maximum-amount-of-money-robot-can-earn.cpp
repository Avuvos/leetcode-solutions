class Solution {
public:
    int dp[501][501][3];
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -2e9;
                }
            }
        }
        auto dfs = [&](auto &dfs, int x, int y, int rem) -> int {
            if (x == n - 1 && y == m - 1) {
                return coins[x][y] > 0 ? coins[x][y] : (rem > 0 ? 0 : coins[x][y]);
            }
            if (dp[x][y][rem] != -2e9) {
                return dp[x][y][rem];
            }
            int skip = -1e9, skip2 = -1e9, use = -1e9, use2 = -1e9;
            if (x + 1 < n) {
                skip = coins[x][y] + dfs(dfs, x + 1, y, rem);
                if (rem > 0) {
                    use = dfs(dfs, x + 1, y, rem - 1);
                }
            }
            if (y + 1 < m) {
                skip2 = coins[x][y] + dfs(dfs, x, y + 1, rem);
                if (rem > 0) {
                    use2 = dfs(dfs, x, y + 1, rem - 1);
                }
            }
            return dp[x][y][rem] = max({skip, skip2, use, use2});
            
        };
        
        return dfs(dfs, 0, 0, 2);
    }
};
