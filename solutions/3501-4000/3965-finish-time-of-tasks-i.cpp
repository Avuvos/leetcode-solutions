class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
        }
        auto dfs = [&](auto &dfs, int u, int p) -> long long {
            if (g[u].size() == 0) {
                return baseTime[u];
            }
            long long mn = 1e18, mx = -1e18;
            for (auto &v: g[u]) {
                long long cr = dfs(dfs, v, u);
                mn = min(mn, cr);
                mx = max(mx, cr);
            }
            return 2 * mx - mn + baseTime[u];
        };
        return dfs(dfs, 0, -1);
    }
};
