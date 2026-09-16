class Solution {
public:
    const int INF = 1e9 + 2;
    const vector<pair<int, int>> DIRS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    const int START_DIR = 4; 
    int dp[76][76][76][5];
    int minCost(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size(), m = grid[0].size();
        auto dfs = [&](auto &dfs, int i, int j, int t, int last_dir) -> int {
            if (t > k) {
                return INF;
            }
            if (i == n - 1 && j == m - 1) {
                return grid[i][j];
            }
            if (dp[i][j][t][last_dir] != -1) {
                return dp[i][j][t][last_dir];
            }
            int best = INF;
            for (int d = 0; d < DIRS.size(); d++) {
                int nt = (d == last_dir || last_dir == START_DIR ? t : t + 1);
                int ni = i + DIRS[d].first;
                int nj = j + DIRS[d].second;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                best = min(best, grid[i][j] + dfs(dfs, ni, nj, nt, d));
            }
            return dp[i][j][t][last_dir] = best;
        };
        int ans = dfs(dfs, 0, 0, 0, START_DIR);
        return ans < INF ? ans : -1;
    }
};
