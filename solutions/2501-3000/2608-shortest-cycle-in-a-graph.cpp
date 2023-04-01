class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 1e9;
        for (int node = 0; node < n; node++) {
            vector<bool> seen(n + 1, false);
            vector<int> dist(n + 1, 0);
            queue<pair<int, int>> q;
            q.push({node, -1});
            dist[node] = 0;
            seen[node] = true;
            int d = 0;
            int curAns = 1e9;
            while (!q.empty()) {
                int sz = q.size();
                for (int iter = 0; iter < sz; iter++) {
                    auto [u, p] = q.front(); q.pop();
                    dist[u] = d;
                    for (auto &v: g[u]) {
                        if (v == p) continue;
                        if (seen[v]) {
                            curAns = min(curAns, d + dist[v] + 1);
                        } else {
                            seen[v] = true;
                            dist[v] = d + 1;
                            q.push({v, u});
                        }
                    }
                }
                d++;
            }
            ans = min(ans, curAns);
        }
        return (ans != 1e9 ? ans : -1);
    }
};
