class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int left = n, right = 0;
        int top = n, bot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bot = max(bot, i);
                }
            }
        }
        return (bot - top + 1) * (right - left + 1);
    }
};
