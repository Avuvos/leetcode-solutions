class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        auto dfs = [&](auto &dfs, int u, int p) -> int {
            if (g[u].size() == 0) {
                return score[u];
            }
            int s = 0, mn = 1e9;
            for (auto &v: g[u]) {
                int val = dfs(dfs, v, u);
                s += val;
                mn = min(mn, val);
            }
            
            if (op[u] == 1) {
                return s + score[u] - mn;
            }
            return s + score[u] - min(0, mn);
        };
        return dfs(dfs, 0, -1);
    }
};
