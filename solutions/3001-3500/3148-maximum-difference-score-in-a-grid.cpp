class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        const int INF = 1e9 + 2;
        vector<vector<int>> mins(n, vector<int>(m, INF));
        int best = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) mins[i][j] = min(mins[i][j], mins[i - 1][j]);
                if (j > 0) mins[i][j] = min(mins[i][j], mins[i][j - 1]);
                best = max(best, grid[i][j] - mins[i][j]);
                mins[i][j] = min(mins[i][j], grid[i][j]);
            }
        }
        return best;
    }
};
