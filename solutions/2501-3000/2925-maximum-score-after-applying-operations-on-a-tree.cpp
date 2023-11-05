class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = (int) edges.size();
        n++;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        auto dfs = [&](auto dfs, int u, int p, int skipped_parent) -> long long {
            if (dp[u][skipped_parent] != -1) {
                return dp[u][skipped_parent];
            }
            long long op1 = values[u], op2 = 0;
            bool leaf = true;
            for (auto &v: g[u]) {
                if (v == p) continue;
                leaf = false;
                op1 += dfs(dfs, v, u, skipped_parent);
                op2 += dfs(dfs, v, u, true);
            }
            if (leaf && !skipped_parent) {
                op1 = -1e17;
            }
            return dp[u][skipped_parent] = max(op1, op2);
        };
        return dfs(dfs, 0, -1, 0);
    }
};
