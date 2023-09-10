class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        string s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                    s += to_string(grid[i][j]);
                }
            }
        }
        if (cnt == 0) {
            return 0;
        }
        int ans = 1e9;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 0) {
                    for (int nx = 0; nx < n; nx++) {
                        for (int ny = 0; ny < n; ny++) {
                            if (grid[nx][ny] > 1) {
                                grid[nx][ny]--;
                                grid[x][y]++;
                                ans = min(ans, abs(x - nx) + abs(y - ny) + minimumMoves(grid));
                                grid[x][y]--;
                                grid[nx][ny]++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
