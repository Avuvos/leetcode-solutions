class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        auto dfs = [&](auto dfs, int u, int p, int seconds) -> double {
            int deg = 0;
            double sum = 0;
            if (seconds == t) {
                return u == target;
            }
            
            for (auto &v: g[u]) {
                if (v == p) continue;
                deg++;
                sum += dfs(dfs, v, u, seconds + 1);
            }
            if (deg == 0) {
                return u == target;
            }
            return (double) sum / deg;
        };
        
        return dfs(dfs, 1, -1, 0);
    }
};
