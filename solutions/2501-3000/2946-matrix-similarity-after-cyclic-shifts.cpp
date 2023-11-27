class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = (int) mat.size(), m = mat[0].size();
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % 2 == 1) {
                    a[i][j] = mat[i][(j + k) % m]; 
                } else {
                    a[i][j] = mat[i][(100*m + j - k) % m];
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ok &= (a[i][j] == mat[i][j]);
            }
        }
        return ok;
    }
};
