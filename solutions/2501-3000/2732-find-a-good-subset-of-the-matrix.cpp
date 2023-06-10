class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        map<int, int> mp;
        for (int r = 0; r < R; r++) {
            int cur = 0;
            for (int c = 0; c < C; c++) {
                if (grid[r][c]) {
                    cur += (1 << c);
                }
            }
            if (cur == 0) return vector<int>{r};
            
            for (int mask = 0; mask < (1 << C); mask++) {
                if (((mask & cur) == 0) && mp.count(mask)) {
                    return vector<int>{mp[mask], r};
                }
            }
            
            mp[cur] = r;
        }
        
        return vector<int>{};
    }
};
