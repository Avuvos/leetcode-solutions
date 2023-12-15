class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<int>> dist(n, vector<int>(n, maxDistance + 2));
            for (int i = 0; i < n; i++) {
                dist[i][i] = 0;
            }
            for (auto r: roads) {
                if (((mask >> r[0]) & 1) && ((mask >> r[1]) & 1)) {
                    dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
                    dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2]);
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    if (!((mask >> i) & 1)) continue;
                    for (int j = 0; j < n; j++) {
                        if (!((mask >> j) & 1)) continue;
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!((mask >> i) & 1)) continue;
                for (int j = 0; j < n; j++) {
                    if (!((mask >> j) & 1)) continue;
                    ok &= (dist[i][j] <= maxDistance);
                    if (!ok) break;
                }
                if (!ok) break;
            }
            ans += ok;
        }
        return ans;
    }
};
