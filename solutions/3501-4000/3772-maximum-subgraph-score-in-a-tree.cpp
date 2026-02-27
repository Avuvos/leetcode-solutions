class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dp(n), ans(n);
        auto dfs = [&](auto &dfs, int u, int p) -> void {
            dp[u] = good[u] ? 1 : -1;
            for (auto &v: g[u]) {
                if (v == p) continue;
                dfs(dfs, v, u);
                dp[u] += max(0, dp[v]);
            }
        };
        dfs(dfs, 0, -1);
        ans[0] = dp[0];
        auto dfs2 = [&](auto &dfs2, int u, int p) -> void {
            for (auto &v: g[u]) {
                if (v == p) continue;
                ans[v] = dp[v] + max(0, ans[u] - max(0, dp[v]));
                dfs2(dfs2, v, u);
            }
        };
        dfs2(dfs2, 0, -1);
        return ans;
    }
};
