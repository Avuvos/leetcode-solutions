class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        typedef long long ll;
        typedef pair<ll, ll> PII;
        const int inf = 1e9+2;
        typedef priority_queue<PII, vector<PII>, greater<>> min_priority_queue_PII;
        auto fast_dijkstra = [&](int start) -> vector<int> {
            vector<int> dist(n, inf);
            min_priority_queue_PII pq;
            pq.push(make_pair(0, start));
            dist[start] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (dist[u] != d) continue;// we just left it in pq until now instead of delete when we updated dist[u].
                if (disappear[u] < d) {
                    dist[u] = inf;
                    continue;
                }
                for (auto [v, w]: g[u]) {
                    if (dist[u] + w < dist[v] && dist[u] + w < disappear[v]) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
            return dist;
        };
        auto ans = fast_dijkstra(0);
        for (int i = 0; i < n; i++) {
            if (ans[i] == inf) ans[i] = -1;
        }
        return ans;
    }
};
