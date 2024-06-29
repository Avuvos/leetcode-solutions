class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> g(n);
        vector<int> visited(n, false);
        for (auto &e: edges) {
            g[e[1]].push_back(e[0]);
        }
        
        
        auto dfs = [&](auto dfs, int u) -> void {
            visited[u] = true;
            for (auto &v: g[u]) {
                if (visited[v]) continue;
                dfs(dfs, v);
            }
        };
        
        for (int i = 0; i < n; i++) {
            visited.assign(n, false);
            dfs(dfs, i);
            for (int j = 0; j < n; j++) {
                if (!visited[j] || i == j) continue;
                ans[i].push_back(j);
            }
        }
        return ans;
    }
};
