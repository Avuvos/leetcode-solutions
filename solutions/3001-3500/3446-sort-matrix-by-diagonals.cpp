class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<pair<int, int>>> mp_ind;
        map<int, vector<int>> mp_vals;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = i - j;
                mp_ind[d].push_back({i, j});
                mp_vals[d].push_back(grid[i][j]);
            }
        }
        for (auto &[key, val]: mp_vals) {
            if (key < 0) {
                sort(val.rbegin(), val.rend());
            } else {
                sort(val.begin(), val.end());
            }
        }
        
        for (auto [key, ind]: mp_ind) {
            auto vals = mp_vals[key];
            for (auto [i, j]: ind) {
                grid[i][j] = vals.back();
                vals.pop_back();
            }
        }
        return grid;
    }
};
