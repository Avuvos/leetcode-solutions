class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> PII;
    typedef priority_queue<PII, vector<PII>, greater<>> min_priority_queue_PII;
    const ll INF = 1e18;
    const int SMALL_INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int m = (int) edges.size();
        vector<set<pair<ll, ll>>> g(n);
        vector<vector<int>> ans(m);
        set<pair<int, int>> modif;
        map<pair<int, int>, int> edge_to_index;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w == -1) {
                w = (int) SMALL_INF;
                ll mn = min(u, v), mx = max(u, v);
                modif.insert({mn, mx});
                edge_to_index[{mn, mx}] = i;
            }
            g[u].insert({v, (ll) w});
            g[v].insert({u, (ll) w});
            ans[i] = {u, v, (int) w};
            edges[i][2] = (int) w;
        }
        vector<ll> dist;
        vector<ll> nxt;
        auto dijkstra = [&](int src, int dst) {
            dist = vector<ll>(n,INF);
            nxt = vector<ll>(n, -1);
            min_priority_queue_PII pq;

            pq.push(make_pair(0, src));
            dist[src] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (dist[u] != d) continue;// we just left it in pq until now instead of delete when we updated dist[u].
                for (auto [v, w]: g[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        nxt[v] = u;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        };
        dijkstra(source, destination);
        if (dist[destination] == INF || dist[destination] < target) {
            return {};
        }
        if (dist[destination] == target) {
            return ans;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w == SMALL_INF) {
                ll prevW = edges[i][2];
                ll newW = 1;
                g[u].erase({v, prevW});
                g[v].erase({u, prevW});
                g[u].insert({v, newW});
                g[v].insert({u, newW});  
                ans[i] = {u, v, (int) newW};
                edges[i][2] = (int) newW;
            }
        }
        
        while (true) {
            dijkstra(source, destination);
            ll diff = target - dist[destination];
            if (diff == 0) {
                return ans;
            }
            ll x = destination;
            vector<int> indices;
            while (x != source) {
                ll p = nxt[x];
                ll mn = min(x, p), mx = max(x, p);
                if (modif.contains({mn, mx})) {
                    indices.push_back(edge_to_index[{mn, mx}]);
                }
                x = p;
            }
    
            ll current_dist = dist[destination];
            if (target < current_dist) break;
            
            if (target == current_dist) {
                return ans;  
            } 
            for (auto index: indices) {
                ll u = edges[index][0], v = edges[index][1], prevW = edges[index][2];
                ll delta = target - current_dist;
                if (delta == 0) break;
                g[u].erase({v, prevW});
                g[v].erase({u, prevW});
                ll newW = delta + 1;
                g[u].insert({v, newW});
                g[v].insert({u, newW});
                ans[index][2] = (int)newW;
                break;
            }
        }
        return {};
    }
};
