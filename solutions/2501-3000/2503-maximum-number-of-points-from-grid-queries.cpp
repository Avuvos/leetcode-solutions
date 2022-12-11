typedef priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<>> min_pq;
class Solution {
public:
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> lst;
        vector<vector<bool>> seen = vector(n, vector<bool>(m, false));
        
        min_pq pq;
        pq.push({grid[0][0], 0, 0});
        seen[0][0] = true;
        while (!pq.empty()) {
            tuple<int, int, int> curr = pq.top(); pq.pop();
            int val = get<0>(curr);
            int x = get<1>(curr);
            int y = get<2>(curr);
            if (x - 1 >= 0 && !seen[x - 1][y]) {
                grid[x - 1][y] = max(grid[x - 1][y], val);
                seen[x - 1][y] = true;
                pq.push({grid[x - 1][y], x - 1, y});
            }
            if (x + 1 < n && !seen[x + 1][y]) {
                grid[x + 1][y] = max(grid[x + 1][y], val);
                seen[x + 1][y] = true;
                pq.push({grid[x + 1][y], x + 1, y});
            }
            if (y - 1 >= 0 && !seen[x][y - 1]) {
                grid[x][y - 1] = max(grid[x][y - 1], val);
                seen[x][y - 1] = true;
                pq.push({grid[x][y - 1], x, y - 1});
            }
            if (y + 1 < m && !seen[x][y + 1]) {
                grid[x][y + 1] = max(grid[x][y + 1], val);
                seen[x][y + 1] = true;
                pq.push({grid[x][y + 1], x, y + 1});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lst.push_back(grid[i][j]);
            }
        }
        
        sort(lst.begin(), lst.end());
        vector<int> ans(queries.size(), 0);
        for (int q = 0; q < queries.size(); q++) {
            int target = queries[q];
            auto it = lower_bound(lst.begin(), lst.end(), target);
            ans[q] = (it - lst.begin());
        }
        return ans;
    }
};
