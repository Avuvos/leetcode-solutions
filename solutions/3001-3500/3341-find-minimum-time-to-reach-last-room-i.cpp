class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minTimeToReach(vector<vector<int>>& a) {
        const long long inf = 1e18;
        int n = a.size(), m = a[0].size();
        
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        priority_queue<tuple<int, int, int>, vector<tuple<int ,int, int>>, greater<>> pq;
        vector<vector<long long>> dist(n, vector<long long>(m, inf));
        dist[0][0] = 0;
        pq.emplace(dist[0][0], 0, 0);
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (d != dist[x][y]) continue;
            for (auto [dx, dy]: DIRECTIONS) {
                int nx = x + dx;
                int ny = y + dy;
                if (!valid(nx, ny)) continue;
                long long next_dist = d + 1 + max(0, a[nx][ny] - d);
                if (next_dist < dist[nx][ny]) {
                    dist[nx][ny] = next_dist;
                    pq.emplace(next_dist, nx, ny);
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
