class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        vector<bool> good(n, true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (grid[i][j] == 1) {
                    good[j] = false;
                } else {
                    good[i] = false;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (good[i]) {
                return i;
            }
        }
        return -1;
    }
};
