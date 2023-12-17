class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        vector<bool> seen(n * n + 1, false);
        vector<int> ans(2, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[grid[i][j]]) {
                    ans[0] = grid[i][j];
                }
                seen[grid[i][j]] = true;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (!seen[i]) {
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};
