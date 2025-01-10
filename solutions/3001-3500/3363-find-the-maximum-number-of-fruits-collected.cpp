class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        auto dfs1 = [&](auto &dfs1, int x, int y) -> int {
            if (x == n - 1 && y == n - 1) {
                return 0;
            }
            if (y >= x) {
                return -1e9;
            }
            if (dp1[x][y] != -1) {
                return dp1[x][y];
            }
            int op1 = 0, op2 = 0, op3 = 0;
            if (x > 0) {
                op1 = dfs1(dfs1, x - 1, y + 1);
            }
            op2 = dfs1(dfs1, x, y + 1);
            if (x + 1 < n) {
                op3 = dfs1(dfs1, x + 1, y + 1);
            }
            return dp1[x][y] = fruits[x][y] + max({op1, op2, op3});
        };
        ans += dfs1(dfs1, n - 1, 0);
        
        
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        auto dfs2 = [&](auto &dfs2, int x, int y) -> int {
            if (x == n - 1 && y == n - 1) {
                return 0;
            }
            if (x >= y) {
                return -1e9;
            }
            if (dp2[x][y] != -1) {
                return dp2[x][y];
            }
            int op1 = 0, op2 = 0, op3 = 0;
            if (y > 0) {
                op1 = dfs2(dfs2, x + 1, y - 1);
            }
            op2 = dfs2(dfs2, x + 1, y);
            if (y + 1 < n) {
                op3 = dfs2(dfs2, x + 1, y + 1);
            }
            return dp2[x][y] = fruits[x][y] + max({op1, op2, op3});
        };
        
        ans += dfs2(dfs2, 0, n - 1);
        return ans;
    }
};
