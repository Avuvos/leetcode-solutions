class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = (int) edges.size();
        n++;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dp(n, vector<int>(25, -1));
        auto dfs = [&](auto dfs, int u, int p, int cnt) -> int {
            if (dp[u][cnt] != -1) {
                return dp[u][cnt];
            }
            int coin = coins[u] / (1 << cnt);
            int op1 = coin / 2;
            int op2 = coin - k;
            for (auto &v: g[u]) {
                if (v == p) continue;
                op1 += dfs(dfs, v, u, min(cnt + 1, 24));
                op2 += dfs(dfs, v, u, min(cnt, 24));
            }
            return dp[u][cnt] = max(op1, op2);
        };
        return dfs(dfs, 0, -1, 0);
    }
};
