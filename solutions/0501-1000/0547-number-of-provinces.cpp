class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int) isConnected.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> seen(n, false);
        
        function<void(int)> dfs = [&](int u) {
            seen[u] = true;
            for (auto &v: g[u]) {
                if (!seen[v]) {
                    dfs(v);
                }
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};
