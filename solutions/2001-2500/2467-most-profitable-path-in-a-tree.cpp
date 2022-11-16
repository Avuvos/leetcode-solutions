class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> deg;
    void dfs(int u, int p) {
        parent[u] = p;
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = edges.size() + 1;
        adj = vector<vector<int>>(n);
        parent = vector<int>(n);
        deg = vector<int>(n, 0);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        int bob_steps = 0;
        vector<bool> bob_seen(n, false);
        dfs(0, -1);
        int cur = bob;
        while (cur != 0) {
            bob_steps++;
            bob_seen[cur] = true;
            cur = parent[cur];
        }
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, amount[0]});
        visited[0] = true;
        int alice_steps = 1;
        long long res = LONG_LONG_MIN;
        while (!q.empty()) {
            int qsize = q.size();
            bob_steps--;
            for (int i = 0; i < qsize; i++) {
                pair<int, long long> cur = q.front(); q.pop();
                int node = cur.first;
                long long val = cur.second;
                if (deg[node] == 1 && node != 0) {
                    res = max(res, val);
                }
                for (auto nei: adj[node]) {
                    if (visited[nei]) continue;
                    visited[nei] = true;
                    if (bob_seen[nei]) { //node is in the path for bob
                        if (alice_steps > bob_steps) q.push({nei, val});
                        else if (alice_steps == bob_steps) q.push({nei, val + amount[nei] / 2});
                        else q.push({nei, val + amount[nei]});
                    } else { //node is unrelated to bob
                        q.push({nei, val + amount[nei]});
                    }
                }
            }
            alice_steps++;
        }
        return res;
    }
};
