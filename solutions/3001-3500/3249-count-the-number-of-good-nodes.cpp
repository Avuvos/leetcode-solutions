class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = (int) edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        auto dfs = [&](auto &dfs, int u, int p) -> int {
            int sz = 1;
            set<int> sizes;
            for (auto &v: g[u]) {
                if (v == p) continue;
                int child_sz = dfs(dfs, v, u);
                sz += child_sz;
                sizes.insert(child_sz);
            }
            if (sizes.size() <= 1) {
                ans++;
            }
            return sz;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
