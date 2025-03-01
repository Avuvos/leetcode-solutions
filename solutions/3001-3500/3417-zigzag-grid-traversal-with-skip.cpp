class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    if (t % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                    t ^= 1;
                }
            } else {
                for (int j = m - 1; j >= 0; j--) {
                    if (t % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                    t ^= 1;
                }
            }
        }
        return ans;
    }
};
