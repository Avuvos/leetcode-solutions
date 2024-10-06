class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        for (auto &e: invocations) {
            g[e[0]].push_back(e[1]);
        }
        vector<int> ans;
        vector<int> susp(n, false);
        auto dfs = [&](auto &dfs, int u) -> void {
            susp[u] = true;
            for (auto &v: g[u]) {
                if (susp[v]) continue;
                dfs(dfs, v);
            }
        };
        dfs(dfs, k);
        bool invoked = false;
        for (int node = 0; node < n; node++) {
            if (susp[node]) continue;
            for (auto &nei: g[node]) {
                if (susp[nei]) {
                    invoked = true;
                }
            }
        }
        for (int node = 0; node < n; node++) {
            if (!susp[node] || invoked) {
                ans.push_back(node);
            }
        }
        return ans;
    }
};
