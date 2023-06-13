class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = (int) grid.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool eq = true;
                int x = 0;
                while (x < n) {
                    if (grid[i][x] != grid[x][j]) {
                        eq = false;
                        break;
                    }
                    x++;
                }
                ans += eq;
            }
        }
        return ans;
    }
};
