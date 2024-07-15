class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> ps_x(n + 1, vector<int>(m + 1, 0));
        for (int row = 1; row < n + 1; ++row) {
            for (int col = 1; col < m + 1; ++col) {
                int val = grid[row - 1][col - 1] == 'X' ? 1 : grid[row - 1][col - 1] == 'Y' ? -1 : 0;
                ps[row][col] = val + ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1];
                int one_val = grid[row - 1][col - 1] == 'X';
                ps_x[row][col] = one_val + ps_x[row - 1][col] + ps_x[row][col - 1] - ps_x[row - 1][col - 1];
            }
        }

        auto sumRegion = [&](vector<vector<int>>& ps, int top_row, int left_col, int bot_row, int right_col) {
            return ps[bot_row + 1][right_col + 1] - ps[bot_row + 1][left_col] - ps[top_row][right_col + 1] + ps[top_row][left_col];
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ok = sumRegion(ps, 0, 0, i, j) == 0 && sumRegion(ps_x, 0, 0, i, j) > 0;
                ans += ok;
            }
        }
        return ans;
    }
};
