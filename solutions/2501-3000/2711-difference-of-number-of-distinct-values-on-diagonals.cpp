class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = i, y = j;
                set<int> topleft;
                set<int> botright;
                int nx, ny;
                for (int k = 1; k < max(n, m); k++) {
                    nx = x - 1*k, ny = y - 1*k;;
                    if (nx < 0 or ny < 0) break;
                    topleft.insert(grid[nx][ny]);
                }
                for (int k = 1; k < max(n, m); k++) {
                    nx = x + 1*k, ny = y + 1*k;;
                    if (nx >= n or ny >= m) break;
                    botright.insert(grid[nx][ny]);
                }
                ans[i][j] = abs((int)botright.size() - (int)topleft.size());
            }
        }
        return ans;
    }
};
