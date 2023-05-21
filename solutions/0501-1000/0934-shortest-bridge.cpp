class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1) return;
            grid[x][y] = 2;
            dfs(x - 1, y);
            dfs(x + 1, y);
            dfs(x, y - 1);
            dfs(x, y + 1);
        };
        
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    ok = true;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        
        
        
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        int dist = 0;
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy]: vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1) continue;
                    if (grid[nx][ny] == 2) return dist;
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }
            dist++;
        }
        return -1;
    }
};
