class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        auto dfs = [&](auto &dfs, int u, int p, vector<int>& dist) -> void {
            for (auto &v: g[u]) {
                if (v == p) continue;
                dist[v] = dist[u] + 1;
                dfs(dfs, v, u, dist);
            }
        };

        vector<int> dx(n, 0), dy(n, 0), dz(n, 0);
        dfs(dfs, x, -1, dx);
        dfs(dfs, y, -1, dy);
        dfs(dfs, z, -1, dz);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> d = {dx[i], dy[i], dz[i]};
            sort(d.begin(), d.end());
            if (1LL*d[0]*d[0] + 1LL*d[1]*d[1] == 1LL*d[2]*d[2]) {
                ans++;
            }
        }
        return ans;




    }
};
