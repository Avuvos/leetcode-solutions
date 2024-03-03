class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int cx = n / 2, cy = n / 2;
        vector<int> belong(3, 0);
        vector<int> not_belong(3, 0);
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, -1}, {-1, 1}};
        belong[grid[cx][cy]]++;
        grid[cx][cy] = -1;
        for (auto [dx, dy]: directions) {
            int nx = cx + dx;
            int ny = cy + dy;
            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                belong[grid[nx][ny]]++;
                grid[nx][ny] = -1;
                nx += dx;
                ny += dy;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) continue;
                not_belong[grid[i][j]]++;
            }
        }
        int ans = n * n + 17;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (i == j) continue;
                int cost_belong = belong[0]+belong[1]+belong[2]-belong[i];
                int cost_not_belong = not_belong[0]+not_belong[1]+not_belong[2]-not_belong[j];
                ans = min(ans, cost_belong + cost_not_belong);
            }
        }
               return ans;
    }
};
