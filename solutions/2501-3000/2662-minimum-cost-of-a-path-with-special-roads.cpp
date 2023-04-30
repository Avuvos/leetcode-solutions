class Solution {
public:
    typedef long long ll;
    typedef tuple<int, int, ll> PII;
    typedef priority_queue<PII, vector<PII>, greater<>> min_priority_queue_PII;
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int, int>, vector<tuple<int, int, ll>>> g;
        int sx = start[0], sy = start[1];
        int ex = target[0], ey = target[1];
        auto d = [&](int x1, int y1, int x2, int y2) -> ll {
            return abs(x1 - x2) + abs(y1 - y2);
        };
        g[make_pair(sx, sy)].push_back({ex, ey, d(sx, sy, ex, ey)});
        vector<pair<int, int>> all;
        all.emplace_back(sx, sy);
        all.emplace_back(ex, ey);
        for (auto &road: specialRoads) {
            int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3];
            all.emplace_back(x1, y1);
            all.emplace_back(x2, y2);
            ll cost = road[4];
            g[make_pair(x1, y1)].push_back({x2, y2, cost});
        }
        
        for (int i = 0; i < all.size(); i++) {
            for (int j = i + 1; j < all.size(); j++) {
                int x1 = all[i].first, y1 = all[i].second, x2 = all[j].first, y2 = all[j].second;
                ll cost = d(x1, y1, x2, y2);
                g[make_pair(x1, y1)].push_back({x2, y2, cost});
                g[make_pair(x2, y2)].push_back({x1, y1, cost});
            }
        }
        
        const ll INF = 1e16;
        map<pair<int, int>, ll> dist;
        for (int i = 0; i < all.size(); i++) {
            int x1 = all[i].first, y1 = all[i].second;
            dist[{x1, y1}] = INF;
        }
        dist[{ex, ey}] = INF;
        min_priority_queue_PII pq;

        pq.push({0, sx, sy});
        dist[{sx, sy}] = 0;

        while (!pq.empty()) {
            auto [dis, x, y] = pq.top(); pq.pop();
            if (dist[{x, y}] != dis) continue;// we just left it in pq until now instead of delete when we updated dist[u].
            for (auto [nx, ny, cost]: g[{x, y}]) {
                if (dist[{x, y}] + cost < dist[{nx, ny}]) {
                    dist[{nx, ny}] = dist[{x, y}] + cost;
                    pq.push({dist[{nx, ny}], nx, ny});
                }
            }
        }
        return dist[{ex, ey}];
    }
};
