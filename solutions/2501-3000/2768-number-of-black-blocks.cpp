class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& C) {
        vector<long long> ans(5, 0);
        ans[0] = (long long) (n - 1) * (m - 1);
        map<pair<int, int>, int> mp;

        vector<pair<int, int>> directions = {{0, 0}, {-1, -1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < C.size(); i++) {
            int x = C[i][0], y = C[i][1];
            for (auto [dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= m || nx < 0 || ny < 0 || ny >= n) continue;
                if (!(nx + 1 < m && ny + 1 < n)) continue;
                int current = mp[make_pair(nx, ny)];
                ans[current]--;
                mp[make_pair(nx, ny)]++;
                ans[current + 1]++;
            }
        }
        return ans;
    }
};
