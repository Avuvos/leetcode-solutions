class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int row = 1; row < n + 1; ++row) {
            for (int col = 1; col < m + 1; ++col) {
                ps[row][col] = grid[row - 1][col - 1] + ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1];
                if (ps[row][col] <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
