class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        swap(n, m);
        long long inf = 1e18 + 2;
        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, inf)));
        dist[0][0][1] = 1;
        priority_queue<tuple<long long, long long, long long, int>, vector<tuple<long long, long long, long long, int>>, greater<>> pq;
        pq.push({dist[0][0][1], 0, 0, 1});
        while (!pq.empty()) {
            auto [d, i, j, p] = pq.top(); pq.pop();
            if (d != dist[i][j][p]) continue;
            if (i == n - 1 && j == m - 1) return d;
            int np = p ^ 1;
            if (i - 1 >= 0) {
                long long c = i * (j + 1) + ((p & 1) ? penalty[i][j] : 0);
                if (d + c < dist[i - 1][j][np]) {
                    dist[i - 1][j][np] = d + c;
                    pq.push({dist[i - 1][j][np], i - 1, j, np});
                }
            }
            if (j - 1 >= 0) {
                long long c = (i + 1) * j + ((p & 1) ? penalty[i][j] : 0);
                if (d + c < dist[i][j - 1][np]) {
                    dist[i][j - 1][np] = d + c;
                    pq.push({dist[i][j - 1][np], i, j - 1, np});
                }
            }
            if (i + 1 < n) {
                long long c = (i + 2) * (j + 1) + ((p & 1) ? 0 : penalty[i][j]);
                if (d + c < dist[i + 1][j][np]) {
                    dist[i + 1][j][np] = d + c;
                    pq.push({dist[i + 1][j][np], i + 1, j, np});
                }
            }
            if (j + 1 < m) {
                long long c = (i + 1) * (j + 2) + ((p & 1) ? 0 : penalty[i][j]);
                if (d + c < dist[i][j + 1][np]) {
                    dist[i][j + 1][np] = d + c;
                    pq.push({dist[i][j + 1][np], i, j + 1, np});
                }
            }
            if (d + penalty[i][j] < dist[i][j][np]) {
                dist[i][j][np] = d + penalty[i][j];
                pq.push({dist[i][j][np], i, j, np});
            }
        }
        return -1;

    }
};
