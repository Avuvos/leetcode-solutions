class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);
        while (!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();
            if (p != dist[u]) continue;
            for (auto &[v, q]: g[u]) {
                if (dist[v] < dist[u] * q) {
                    dist[v] = dist[u] * q;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[end_node];
    }
};
