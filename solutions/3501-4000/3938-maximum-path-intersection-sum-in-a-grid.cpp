class Solution {
public:
    int kadane(vector<int>& a) {
        int cur = 0, ans = -1e9;
        bool len_two = false, first = true;
        for (auto &x: a) {
            if (!first) {
                ans = max(ans, cur + x);
            }
            if (cur + x >= x) {
                len_two = true;
                cur = cur + x;
            } else {
                len_two = false;
                cur = x;
            }
            if (len_two && !first) {
                ans = max(ans, cur);
            }
            first = false;
        }
        return ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int ans = -1e9;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cols(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cols[j].push_back(grid[i][j]);
                if (i != 0 && i != n - 1 && j != 0 && j != m - 1) {
                    ans = max(ans, grid[i][j]);
                }
            }
        }
        for (auto &v: grid) {
            ans = max(ans, kadane(v));
        }
        for (auto &v: cols) {
            ans = max(ans, kadane(v));
        }
        return ans;
    }
};
