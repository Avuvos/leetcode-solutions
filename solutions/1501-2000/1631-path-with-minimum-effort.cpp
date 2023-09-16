class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> seen = vector<vector<bool>>(n, vector<bool>(m));
        function<bool(int, int, int)> dfs = [&](int x, int y, int bound) { 
            if (x == n - 1 && y == m - 1) {
                return true;
            }
            seen[x][y] = true;
            for (auto [dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || seen[nx][ny]) continue;
                int d = abs(heights[x][y] - heights[nx][ny]);
                if (d <= bound && dfs(nx, ny, bound)) {
                    return true;
                } 
            }
            return false;
        };
        int left = 0, right = 1e9, ans = 1e9;
        while (left <= right) {
            int mid = left + (right - left)/2;
            seen.assign(n, vector<bool>(m, false));
            if (dfs(0, 0, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
