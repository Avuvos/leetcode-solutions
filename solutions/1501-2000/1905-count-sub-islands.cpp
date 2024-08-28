class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = (int) grid1.size(), m = (int) grid1[0].size();
        
        
        auto dfs = [&](auto &dfs, int x, int y) -> bool {
            if (x < 0 || x >= n || y < 0 || y >= m || grid2[x][y] == 0) {
                return true;
            }
            grid2[x][y] = 0;
            bool ok = grid1[x][y] == 1;
            ok &= dfs(dfs, x + 1, y);
            ok &= dfs(dfs, x - 1, y);
            ok &= dfs(dfs, x, y + 1);
            ok &= dfs(dfs, x, y - 1);
            return ok;
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(dfs, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
