class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = grid[0].size();
        vector<long long> rows(n, 0);
        vector<long long> cols(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans += 1LL * (rows[i] - 1) * (cols[j] - 1);
                }
            }
        }
        return ans;
    }
};
