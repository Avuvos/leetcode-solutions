class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for (int ball = 0; ball < n; ball++) {
            int row = 0, col = ball;
            while (row < m && col < n && col >= 0) {
                if (grid[row][col] == 1) {
                    if (col < n - 1 && grid[row][col + 1] == -1) break;
                    row++;
                    col++;
                } else {
                    if (col > 0 && grid[row][col - 1] == 1) break;
                    row++;
                    col--;
                }
            }
            if (row == m && col < n) 
                ans[ball] = col;
        }
        return ans;
    }
};
