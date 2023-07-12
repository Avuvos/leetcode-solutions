class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int u) {
            if (dp[u] != -1) return dp[u];
            dp[u] = 0;
            for (auto &v: graph[u]) {
                if (!dfs(v)) {
                    return 0;
                }
            }
            dp[u] = 1;
            return dp[u];
        };
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) dp[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            dfs(i);
            if (dp[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};
