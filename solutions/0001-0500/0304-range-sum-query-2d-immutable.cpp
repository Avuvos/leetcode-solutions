class NumMatrix {
public:
    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        ps = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    for (int row = 1; row < n + 1; ++row) {
        for (int col = 1; col < m + 1; ++col) {
            ps[row][col] = matrix[row - 1][col - 1] + ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1];
        }
    }
    }
    
    int sumRegion(int top_row, int left_col, int bot_row, int right_col) {
        return ps[bot_row + 1][right_col + 1] - ps[bot_row + 1][left_col] - ps[top_row][right_col + 1] + ps[top_row][left_col];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
