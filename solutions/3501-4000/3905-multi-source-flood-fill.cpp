class Solution {
public:
    vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        priority_queue<tuple<int, int, int, int>> pq;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        int level = n * m + 1;
        for (auto &s: sources) {
            pq.push({level, s[2], s[0], s[1]});
        }
        while (!pq.empty()) {
            auto [lvl, color, row, col] = pq.top(); pq.pop();
            if (ans[row][col] != -1) continue;
            ans[row][col] = color;
            for (auto [dx, dy]: DIRECTIONS) {
                int nrow = row + dx;
                int ncol = col + dy;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == -1) {
                    pq.push({lvl - 1, color, nrow, ncol});
                }
            }
        }
        return ans;
    }
};
