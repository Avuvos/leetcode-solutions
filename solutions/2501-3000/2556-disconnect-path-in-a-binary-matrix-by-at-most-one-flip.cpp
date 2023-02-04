class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 0));
        vector<vector<int>> dp2 = vector<vector<int>>(n, vector<int>(m, 0));
        vector<int> diag(n + m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] = grid[i][j - 1];
                else if (j == 0) dp[i][j] = grid[i - 1][j];
                else dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            } 
        }
        
        if (!dp[n - 1][m - 1]) return true;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                if (i == n - 1 && j == m - 1) dp2[i][j] = 1;
                else if (i == n - 1) dp2[i][j] = grid[i][j + 1];
                else if (j == m - 1) dp2[i][j] = grid[i + 1][j];
                else dp2[i][j] = dp2[i + 1][j] | dp2[i][j + 1];
            }
        } 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] && dp2[i][j]) diag[i + j]++;
            }
        }
        
        for (int i = 1; i < m + n - 2; i++) {
            if (diag[i] == 1) {
                return true;
            }
        }
        return false;
        
    }
};
