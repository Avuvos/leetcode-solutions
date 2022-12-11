class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }
        int res = 0;
        for (int col = 0; col < m; col++) {
            int curMax = 0;
            for (int row = 0; row < n; row++) {
                curMax = max(curMax, grid[row][col]);
            }
            res += curMax;
        }
        return res;
    }
};
