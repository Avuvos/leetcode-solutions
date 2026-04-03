class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) return 0;
        vector<vector<int>> g(n);
        vector<int> color(n);

        auto ok = [&](int d) -> bool {
            for (int i = 0; i < n; i++) {
                g[i].clear();
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) < d) {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
            fill(color.begin(), color.end(), -1);
            auto dfs = [&](auto &dfs, int u, int p, int c) -> bool {
                if (color[u] != -1) return true;
                color[u] = c;
                for (auto &v: g[u]) {
                    if (v == p) continue;
                    if (color[v] == c) {
                        return false;
                    }
                    if (!dfs(dfs, v, u, c ^ 1)) {
                        return false;
                    }
                }
                return true;
            };
            for (int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    if (!dfs(dfs, i, -1, 0)) {
                        return false;
                    }
                }
            }
            return true;
        };

        int left = 0, right = 1e9 + 2, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ok(mid)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
