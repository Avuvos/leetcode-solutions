class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = (int) graph.size();
        vector<int> color(n, -1);
        for (int node = 0; node < n; node++) {
            if (color[node] != -1) continue;
            queue<pair<int, int>> q;
            q.push({node, 0});
            while (!q.empty()) {
                int sz = (int) q.size();
                for (int i = 0; i < sz; i++) {
                    auto [u, col] = q.front(); q.pop();
                    if (color[u] != -1) continue;
                    color[u] = col;
                    for (auto v: graph[u]) {
                        if (color[v] == color[u]) {
                            return false;
                        }
                        if (color[v] == -1) {
                            q.push({v, 1 - col});
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
