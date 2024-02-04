class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = (int) image.size(), m = (int) image[0].size();
        vector<vector<int>> sums(n, vector<int>(m, 0));
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool valid = true;
                int x = i, y = j;
                for (auto [dx, dy]: directions) {
                    int nx = x + dx, ny = y + dy;
                    valid &= (nx >= 0 && ny >= 0 && nx < n && ny < m);
                }
                if (!valid) continue;
                for (auto [dx, dy]: directions) {
                    int nx = x + dx, ny = y + dy;
                    if (abs(x - nx) + abs(y - ny) == 1) {
                        valid &= abs(image[x][y] - image[nx][ny]) <= threshold;
                    }
                    for (auto [dx2, dy2]: directions) {
                        int nx2 = x + dx2, ny2 = y + dy2;
                        if (abs(nx - nx2) + abs(ny - ny2) == 1) {
                            valid &= abs(image[nx][ny] - image[nx2][ny2]) <= threshold;
                        }
                    }
                }
                if (!valid) continue;
                int avg = image[i][j];
                for (auto [dx, dy]: directions) {
                    int nx = x + dx, ny = y + dy;
                    avg += image[nx][ny];
                }
                avg /= 9;
                cnt[i][j]++;
                sums[i][j] += avg;
                for (auto [dx, dy]: directions) {
                    int nx = x + dx, ny = y + dy;
                    cnt[nx][ny]++;
                    sums[nx][ny] += avg;
                }   
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt[i][j] == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] = sums[i][j] / cnt[i][j];
                }
            }
        }
        return ans;
    }
};
