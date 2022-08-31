class Solution {
public:
    vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& seen) {
        seen[x][y] = true;
        for (auto [dx, dy]: directions) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size() || seen[nx][ny]) continue;
            if (heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, heights, seen);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> seenPacific(n, vector(m, false));
        vector<vector<bool>> seenAtlantic(n, vector(m, false));
        vector<vector<int>> res;

        for (int col = 0; col < m; ++col) {
            dfs(0, col, heights, seenPacific);
            dfs(n - 1, col, heights, seenAtlantic);
        }

        for (int row = 0; row < n; ++row) {
            dfs(row, 0, heights, seenPacific);
            dfs(row, m - 1, heights, seenAtlantic);
        }

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (seenPacific[row][col] && seenAtlantic[row][col]) {
                    res.push_back(vector<int>{row, col});
                }
            }
        }
        return res;
    }
};
