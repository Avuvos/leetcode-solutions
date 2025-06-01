class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                int mn = 1e6;
                set<int> values;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        values.insert(grid[x][y]);
                    }
                }
                vector<int> dis(values.begin(), values.end());
                sort(dis.begin(), dis.end());
                for (int x = 0; x + 1 < dis.size(); x++) {
                    mn = min(mn, dis[x + 1] - dis[x]);
                }
                if (mn == 1e6) mn = 0;
                ans[i][j] = mn;
            }
        }
        return ans;
    }
};
