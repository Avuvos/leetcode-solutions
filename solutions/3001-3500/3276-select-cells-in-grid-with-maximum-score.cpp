class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[grid[i][j]].push_back(i);
            }
        }
        vector<pair<int, vector<int>>> locs;
        copy(pos.begin(), pos.end(), back_inserter(locs));
        vector<vector<int>> dp(locs.size(), vector<int>((1 << n), -1));
        auto dfs = [&](auto &dfs, int index, int mask) -> int {
            if (index >= locs.size()) {
                return 0;
            }
            if (dp[index][mask] != -1) {
                return dp[index][mask];
            }
            int best = dfs(dfs, index + 1, mask);
            for (auto &row: locs[index].second) {
                if (((mask >> row) & 1) == 0) {
                    best = max(best, locs[index].first + dfs(dfs, index + 1, mask | (1 << row)));
                }
            }
            return dp[index][mask] = best;
        };
        return dfs(dfs, 0, 0);
    }
};
