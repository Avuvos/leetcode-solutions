class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int i = 0; i < grid[0].size(); i++) {
            int current = 0;
            for (int j = 0; j < grid.size(); j++) {
                string s = to_string(grid[j][i]);
                current = max(current, (int) s.size());
            }
            ans.push_back(current);
        }
        return ans;
    }
};
