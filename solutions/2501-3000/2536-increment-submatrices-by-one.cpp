class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(n, 0));
        for (auto &q: queries) {
            int row1 = q[0], col1 = q[1];
            int row2 = q[2], col2 = q[3];
            for (int row = row1; row <= row2; row++) {
                mat[row][col1]++;
                if (col2 + 1 < n)
                    mat[row][col2 + 1]--;
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                mat[row][col] += mat[row][col - 1];
            }
        }
        return mat;
    }
};
