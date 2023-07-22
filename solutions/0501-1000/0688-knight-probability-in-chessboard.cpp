class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        //dp[i][j][k]
        //is the prob the knight remains on the board if he is on
        //square i, j and has k moves left
        //so obviously dp[i][j][k] = 1/8(sum of dp[ni][nj][k-1])
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}
                ,{1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

        function<double(int, int, int)> dfs = [&](int x, int y, int moves) -> double {
            if (x >= n || y >= n || x < 0 || y < 0) {
                return 0;
            }
            if (moves == 0) {
                return 1;
            }
            if (dp[x][y][moves] != -1.0) {
                return dp[x][y][moves];
            }
            double ans = 0;
            for (auto [dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;
                ans += (1/8.0) * dfs(nx, ny, moves - 1);
            }
            dp[x][y][moves] = ans;
            return ans;
        };
        return dfs(row, column, k);
    }
};
