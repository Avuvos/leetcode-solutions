class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        auto dfs = [&](auto &dfs, int u, int p) -> int {
            int res = 1;
            for (auto &v: g[u]) {
                res = max(res, 1 + dfs(dfs, v, u));
            }
            return res;
        };
        int h = dfs(dfs, 0, -1);
        auto dfs2 = [&](auto &dfs2, int u, int p, int d) -> long long {
            long long res = 1LL * nums[u] * (h - d + 1);
            for (auto &v: g[u]) {
                res += dfs2(dfs2, v, u, d + 1);
            }
            return res;
        };
        return dfs2(dfs2, 0, -1, 1);
    }
};
