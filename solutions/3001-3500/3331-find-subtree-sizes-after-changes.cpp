class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        vector<vector<int>> last(26);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        vector<vector<int>> ng(n);
        auto dfs = [&](auto &dfs, int u) -> void {
            last[s[u] - 'a'].push_back(u);
            for (auto &v: g[u]) {
                int p = s[v] - 'a';
                if (last[p].empty()) {
                    ng[u].push_back(v);
                } else {
                    ng[last[p].back()].push_back(v);
                }
                dfs(dfs, v);
            }
            last[s[u] - 'a'].pop_back();
        };
        dfs(dfs, 0);

        auto dfs2 = [&](auto &dfs2, int u) -> void {
            ans[u] = 1;
            for (auto &v: ng[u]) {
                dfs2(dfs2, v);
                ans[u] += ans[v];
            }
        };
        dfs2(dfs2, 0);
        return ans;
    }
};
