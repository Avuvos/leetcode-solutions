class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            g[i].push_back(i + 1);
        }
        auto get = [&](int src, int target) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(src);
            dist[src] = 0;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (auto &nei: g[cur]) {
                    if (dist[nei] == -1) {
                        dist[nei] = 1 + dist[cur];
                        q.push(nei);
                    }
                }
            }
            return dist[target];
        };
        
        int q = (int) queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            g[u].push_back(v);
            ans[i] = get(0, n - 1);
        }
        return ans;
    }
};
