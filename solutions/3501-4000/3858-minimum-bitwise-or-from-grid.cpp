class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> alive(n, vector<bool>(m, true));
        vector<int> cnt(n, m);
        for (int b = 20; b >= 0; b--) {
            int must_take = false;
            for (int i = 0; i < n; i++) {
                // if all alive elements have this bit, we must take it
                int c = 0;
                for (int j = 0; j < m; j++) {
                    if (!alive[i][j]) continue;
                    if ((grid[i][j] & (1 << b)) == 0) continue;
                    c++;
                }
                if (c == cnt[i]) {
                    must_take = true;
                    break;
                }
            }
            if (must_take) {
                ans |= (1 << b);
                continue;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!alive[i][j]) continue;
                    if ((grid[i][j] & (1 << b)) == 0) continue;
                    alive[i][j] = false;
                    cnt[i]--;
                }
            }
        }
        return ans;
    }
};
