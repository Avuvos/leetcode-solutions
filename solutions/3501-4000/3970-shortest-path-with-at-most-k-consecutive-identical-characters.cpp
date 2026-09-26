class Solution {
public:
    const int INF = 1e9 + 2;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
        dist[0][1] = 0;
        pq.push({0, 1, 0});
        while (!pq.empty()) {
            auto [d, s, u] = pq.top(); pq.pop();
            if (d != dist[u][s]) continue;
            for (auto &[v, w]: g[u]) {
                int nd = d + w;
                int ns = (labels[v] == labels[u]) ? s + 1: 1;
                if (ns <= k && nd < dist[v][ns]) {
                    dist[v][ns] = nd;
                    pq.push({dist[v][ns], ns, v});
                }
            }
        }
        int ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return ans < INF ? ans : -1;
    }
};
