class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < cells.size(); i++) {
            int r = cells[i][0], c = cells[i][1];
            r--, c--;
            grid[r][c] = i + 1;
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto good = [&](int time)-> bool {
            queue<pair<int, int>> q;
            vector<vector<bool>> seen(row, vector<bool>(col, false));
            for (int i = 0; i < col; i++) {
                if (grid[0][i] <= time) continue;
                q.push(make_pair(0, i));
                seen[0][i] = true;
            }
            while (!q.empty()) {
                int sz = (int) q.size();
                for (int iter = 0; iter < sz; iter++) {
                    auto [x, y] = q.front(); q.pop();
                    if (x == row - 1) {
                        return true;
                    }
                    for (auto [dx, dy]: directions) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || ny < 0 || nx >= row || ny >= col || seen[nx][ny] || grid[nx][ny] <= time) continue;
                        seen[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            return false;
        };

        int left = 0, right = row * col + 17, ans = 0;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (good(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
