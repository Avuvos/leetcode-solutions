class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = (int) grid.size();
        vector<vector<int>> a(3 * n, vector<int>(3 * n, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int si = 3 * i, sj = 3 * j;
                if (grid[i][j] == '/') {
                    a[si][sj + 2] = 0;
                    a[si + 1][sj + 1] = 0;
                    a[si + 2][sj] = 0;
                } else if (grid[i][j] == '\\') {
                    a[si][sj] = 0;
                    a[si + 1][sj + 1] = 0;
                    a[si + 2][sj + 2] = 0;
                }
            }
        }
        auto dfs = [&](auto &dfs, int x, int y) -> void {
            if (x < 0 || y < 0 || x >= 3 * n || y >= 3 * n || a[x][y] == 0) {
                return;
            }
            a[x][y] = 0;
            dfs(dfs, x + 1, y);
            dfs(dfs, x - 1, y);
            dfs(dfs, x, y + 1);
            dfs(dfs, x, y - 1);
        };
        
        int ans = 0;
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (a[i][j] == 1) {
                    ans++;
                    dfs(dfs, i, j);
                }
            }
        }
        return ans;
    }
};
