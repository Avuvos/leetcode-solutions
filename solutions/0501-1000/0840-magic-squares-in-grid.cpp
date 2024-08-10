class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        
        
        auto good = [&](int x, int y) -> bool {
            if (x + 2 >= n || y + 2 >= m) {
                return false;
            }
            vector<int> row(3), col(3);
            set<int> vals;
            for (int i = x; i < x + 3; i++) {
                for (int j = y; j < y + 3; j++) {
                    if (grid[i][j] < 1 || grid[i][j] > 9) {
                        return false;
                    }
                    row[i - x] += grid[i][j];
                    col[j - y] += grid[i][j];
                    vals.insert(grid[i][j]);
                }
            }
            if (vals.size() < 9) {
                return false;
            }
            set<int> values;
            values.insert(grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]);
            values.insert(grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2]);
            for (int i = 0; i < 3; i++) {
                values.insert(row[i]);
                values.insert(col[i]);
            }
            return values.size() == 1;
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += good(i, j);
            }
        }
        return ans;
    }
};
