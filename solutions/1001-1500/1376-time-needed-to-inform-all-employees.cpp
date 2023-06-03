class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            g[manager[i]].push_back({i, informTime[manager[i]]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, headID});
        vector<int> dist(n, 1e6);
        dist[headID] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto &[v, w]: g[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};
