class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> furthestRow(m, 0), furthestCol(n, 0);
        queue<pair<int, int>> queue;
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        queue.push({0, 0});
        seen[0][0] = true;
        int cells = 1;
        while (!queue.empty()) {
            int qsize = (int) queue.size();
            for (int iter = 0; iter < qsize; iter++) {
                auto [x, y] = queue.front(); queue.pop();
                
                //check if we got to the end
                if (x == n - 1 && y == m - 1)
                    return cells;
                
                //go through cols
                int startCol = max(furthestCol[x], y);
                for (int col = startCol; col <= min(m - 1, y + grid[x][y]); col++) {
                    furthestCol[x] = max(furthestCol[x], col);
                    if (!seen[x][col]) {
                        seen[x][col] = true;
                        queue.push({x, col});
                    }
                }
                
                //go through rows
                int startRow = max(furthestRow[y], x);
                for (int row = startRow; row <= min(n - 1, x + grid[x][y]); row++) {
                    furthestRow[y] = max(furthestRow[y], row);
                    if (!seen[row][y]) {
                        seen[row][y] = true;
                        queue.push({row, y});
                    }
                }
            }
            cells++;
        }
        return -1;
    }
};
