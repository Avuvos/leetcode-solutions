class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        long long res = 0;
        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid[0].size() - 1; c++) {
                long long current = grid[r][c] + grid[r + 1][c] + grid[r + 1][c - 1] + grid[r + 1][c + 1]
                              + grid[r - 1][c] + grid[r - 1][c - 1] + grid[r - 1][c + 1];
                res = max(res, current);
            }
        }
        return res;
    }
};
