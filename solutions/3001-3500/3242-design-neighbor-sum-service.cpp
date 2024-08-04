class neighborSum {
public:
    int n;
    vector<vector<int>> a;
    map<int, pair<int, int>> mp;
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    const vector<pair<int, int>> DIRECTIONS_DIAG = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    neighborSum(vector<vector<int>>& grid) {
        a = grid;
        n = (int) a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[a[i][j]] = make_pair(i, j);
            }
        }
    }
    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int calc(int x, int y, vector<pair<int, int>> dirs) {
        int ans = 0;
        for (auto [dx, dy]: dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if (valid(nx, ny)) {
                ans += a[nx][ny];
            }
        }
        return ans;
    }
    
    int adjacentSum(int value) {
        auto [x, y] = mp[value];
        return calc(x, y, DIRECTIONS);
    }
    
    int diagonalSum(int value) {
        auto [x, y] = mp[value];
        return calc(x, y, DIRECTIONS_DIAG);
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
