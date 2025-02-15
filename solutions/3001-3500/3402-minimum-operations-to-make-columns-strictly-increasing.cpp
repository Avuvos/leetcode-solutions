class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (grid[i][j] > grid[i - 1][j]) continue;
                int d = grid[i - 1][j] - grid[i][j];
                grid[i][j] += d + 1;
                ans += d + 1;
            }
        }
        return ans;
    }
};
