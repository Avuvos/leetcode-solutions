class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n) ok &= (grid[i][j] == grid[i + 1][j]);
                if (j + 1 < m) ok &= (grid[i][j] != grid[i][j + 1]);
            }
        }
        return ok;
    }
};
