class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto e: times) {
            g[e[0]].push_back({e[1], e[2]});
        }
        int INF = 1e9;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d != dist[node]) continue;
            for (auto &[neib, w]: g[node]) {
                if (dist[node] + w < dist[neib]) {
                    dist[neib] = dist[node] + w;
                    pq.push({dist[neib], neib});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
