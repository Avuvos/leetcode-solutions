class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> c(n, 0);
        int dp[n][26]; //largest path starting from node x with char c
        memset(dp, -1, sizeof(dp));
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
        }
        //dfs1 to check for cycles
        //c[u] = 0 means not seen yet
        //c[u] = 1 means its on the dfs stack right now
        //c[u] = 2 means we are done with u
        function<bool(int)> dfs1 = [&](int u)-> bool {
            c[u] = 1;
            for (auto &v: g[u]) {
                if ((c[v] == 1) || (c[v] == 0 && dfs1(v))) {
                    return true;
                } 
            }
            c[u] = 2;
            return false;
        };

        //dfs2 to fill the dp
        function<void(int)> dfs2 = [&](int u) -> void {
            for (int i = 0; i < 26; i++) dp[u][i] = 0;
            dp[u][colors[u] - 'a'] = 1;
            for (auto &v: g[u]) {
                for (int i = 0; i < 26; i++) {
                    if (dp[v][i] == -1) {
                        dfs2(v);
                    }
                    dp[u][i] = max(dp[u][i], (colors[u]-'a' == i) + dp[v][i]);
                }
            }
        };

        for (int node = 0; node < n; node++) {
            if (c[node] == 2) continue;
            if (dfs1(node)) return -1;
        }

        for (int node = 0; node < n; node++) {
            if (dp[node][0] != -1) continue;
            dfs2(node);
        }

        int ans = 0;
        for (int node = 0; node < n; node++) {
            for (int i = 0; i < 26; i++) {
                ans = max(ans, dp[node][i]);
            }
        }
        return ans;
    }
};
