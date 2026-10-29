class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0;
        unordered_map<int, pair<int, int>> mp{{'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};
        while (true) {
            auto [di, dj] = mp[grid[i][j]];
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == 'X') {
                break;
            }
            grid[i][j] = 'X';
            i = ni, j = nj;
        }
        return {i, j};
    }
};
