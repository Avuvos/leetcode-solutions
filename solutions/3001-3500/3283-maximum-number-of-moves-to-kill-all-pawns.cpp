class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = { {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
    const int INF = 1e9;
    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        int n = 50;
        int m = pos.size();
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(2, vector<int>(1 << m, -1)));
        vector<vector<int>> dist(m + 1, vector<int>(m + 1, INF));
        
        auto valid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < n;
        };
        
        auto calc = [&](int ky, int kx, int ty, int tx) -> int {
            queue<pair<int, int>> q;
            vector<vector<bool>> seen(n, vector<bool>(n, false));
            int dist = 0;
            q.push({ky, kx});
            seen[ky][kx] = true;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    auto [y, x] = q.front(); q.pop();
                    if (y == ty && x == tx) return dist;
                    for (auto [dy, dx]: DIRECTIONS) {
                        int ny = y + dy;
                        int nx = x + dx;
                        if (nx == tx && ny == ty) return dist + 1;
                        if (!valid(ny, nx) || seen[ny][nx]) continue;
                        seen[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
                dist++;
            }
            return -1;
        };
        
        for (int i = 0; i < m; i++) {
            dist[i][m] = dist[m][i] = calc(pos[i][1], pos[i][0], ky, kx);
            for (int j = i + 1; j < m; j++) {
                dist[i][j] = dist[j][i] = calc(pos[i][1], pos[i][0], pos[j][1], pos[j][0]);
            }
        }
        
        auto dfs = [&](auto &dfs, int index, int turn, int mask) -> int {
            if (__builtin_popcount(mask) == m) {
                return 0;
            }
            if (dp[index][turn][mask] != -1) {
                return dp[index][turn][mask];
            }
            int best = (turn == 0 ? -INF : INF);
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) continue;
                int t = dist[index][i];
                if (turn == 0) {
                    best = max(best, t + dfs(dfs, i, turn ^ 1, mask | (1 << i)));
                } else {
                    best = min(best, t + dfs(dfs, i, turn ^ 1, mask | (1 << i)));
                }
            }
            return dp[index][turn][mask] = best;
        };
        
        return dfs(dfs, m, 0, 0);
        
    }
};
