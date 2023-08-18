class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> g(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0], v = roads[i][1];
            g[u].insert(v);
            g[v].insert(u);
        }
        
        int ans = 0;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int current = (int) g[u].size() + (int) g[v].size();
                if (g[u].find(v) != g[u].end()) {
                    current--;
                }
                ans = max(ans, current);
            }
        }
        return ans;
        
    }
};
