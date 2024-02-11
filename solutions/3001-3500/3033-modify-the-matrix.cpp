class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        auto ans = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    for (int k = 0; k < n; k++) {
                        ans[i][j] = max(ans[i][j], matrix[k][j]);
                    }
                }
            }
        }
        return ans;
    }
};
