class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const int INF = 1e9 + 2;
    typedef tuple<int, int, int> TII;
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        
        auto valid = [&](int x, int y) -> bool {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        
        priority_queue<TII, vector<TII>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        pq.emplace(grid[0][0], 0, 0);
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); pq.pop();
            if (t != dist[x][y]) continue; //old value of the cell (x, y)
            for (auto [dx, dy]: DIRECTIONS) {
                int nx = x + dx;
                int ny = y + dy;
                if (!valid(nx, ny)) continue;
                int weight = max(0, grid[nx][ny] - t);
                if (dist[x][y] + weight < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + weight;
                    pq.emplace(dist[nx][ny], nx, ny);
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
