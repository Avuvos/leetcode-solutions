class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;
        int n = (int) grid.size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int dist = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}, {-1, -1}, {-1, 0}, {-1, 1}};
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int iter = 0; iter < sz; iter++) {
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == n - 1) {
                    return dist;
                }
                for (auto [dx, dy]: dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
