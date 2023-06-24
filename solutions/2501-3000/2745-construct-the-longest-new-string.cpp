class Solution {
public:
    int longestString(int x, int y, int z) {
        int dp[51][51][51][3];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int, int)> dfs = [&](int x, int y, int z, int last) {
            if (x == 0 && y == 0 && z == 0) {
                return 0;
            }
            if (dp[x][y][z][last] != -1) {
                return dp[x][y][z][last];
            }
            int op1 = 0, op2 = 0, op3 = 0;
            if (last == 2) {
                if (x > 0) {
                    op1 = 2 + dfs(x - 1, y, z, 0);
                }
                if (z > 0) {
                    op3 = 2 + dfs(x, y, z - 1, 1);
                }
                if (y > 0) {
                    op2 = 2 + dfs(x, y - 1, z, 1);
                }
            }
            else if (last == 0) { //last char was a
                if (y > 0) {
                    op2 = 2 + dfs(x, y - 1, z, 1);
                }
            } else {
                if (x > 0) {
                    op1 = 2 + dfs(x - 1, y, z, 0);
                }
                if (z > 0) {
                    op3 = 2 + dfs(x, y, z - 1, 1);
                }
            }
            int ans = max({op1, op2, op3});
            dp[x][y][z][last] = ans;
            return ans;
        };
        return dfs(x, y, z, 2);
    }
};
