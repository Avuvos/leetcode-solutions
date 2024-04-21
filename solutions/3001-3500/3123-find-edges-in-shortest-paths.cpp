typedef long long ll;
const ll INF = 1e18;
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = (int) edges.size();
        vector<bool> ans(m);
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        
        typedef pair<ll, ll> PII;
        typedef priority_queue<PII, vector<PII>, greater<>> min_priority_queue_PII;
        auto fast_dijkstra = [&](int start) -> vector<ll> {
            vector<ll> dist(n, INF);
            min_priority_queue_PII pq;
            pq.push(make_pair(0, start));
            dist[start] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (dist[u] != d) continue;// we just left it in pq until now instead of delete when we updated dist[u].
                for (auto [v, w]: g[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
            return dist;
        };
        auto dist_from_src = fast_dijkstra(0);
        auto dist_from_target = fast_dijkstra(n - 1);
        ll min_dist = dist_from_src[n - 1];
        ll dist2 = dist_from_target[0];
        assert(min_dist == dist2);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist_from_src[u] + w + dist_from_target[v] == min_dist) {
                ans[i] = true;
            }
            if (dist_from_src[v] + w + dist_from_target[u] == min_dist) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
