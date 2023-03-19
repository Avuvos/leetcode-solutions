class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int target = 1;
        int x = 0, y = 0;
        int n = grid.size();
        vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
        while (target < n*n) {
            bool found = false;
            for (auto [dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] == target) {
                    // cout << target << " " << nx << " " << ny << endl;
                    x = nx, y = ny;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
            target++;
        }
        return true;
    }
};
