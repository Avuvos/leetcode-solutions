class Solution {
public:  
    void reverse_matrix(vector<vector<int>>& matrix) {
        for (auto &row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
    
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_matrix(matrix);
    }
};
