class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = health - grid[0][0];
        priority_queue<tuple<int, int, int>> pq;
        pq.push({health - grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [h, x, y] = pq.top(); pq.pop();
            if (dp[x][y] != h) continue; 
            for (auto [dx, dy]: DIRECTIONS) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int next_health = h - grid[nx][ny];
                    if (next_health > 0 && next_health > dp[nx][ny]) {
                        dp[nx][ny] = next_health;
                        pq.push({dp[nx][ny], nx, ny});
                    }
                }
            }
        }
        return dp[n - 1][m - 1] > 0;
    }
};
