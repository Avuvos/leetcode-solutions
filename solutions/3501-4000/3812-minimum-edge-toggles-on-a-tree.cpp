class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<int>> g(n);
        vector<int> parent(n), num_children(n), q, nq, ans;
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n - 1; i++) {
            auto &e = edges[i];
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            int mn = min(e[0], e[1]), mx = max(e[0], e[1]);
            mp[{mn, mx}] = i;
        }

        auto dfs = [&](auto &dfs, int u, int p = -1) -> void {
            parent[u] = p;
            for (auto &v: g[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                }
            }
        };
        dfs(dfs, 0);
        
        for (int i = 1; i < n; i++) {
            if (g[i].size() == 1) { // leaf
                q.push_back(i);
            }
            num_children[i] = g[i].size();
        }  


        while (!q.empty()) {
            for (auto &v: q) {
                int pv = parent[v];
                if (pv != -1 && --num_children[pv] == 1) {
                    nq.push_back(pv);
                }
                if (start[v] == target[v]) {
                    continue;
                } 
                start[pv] = start[pv] == '0' ? '1' : '0';
                int mn = min(v, pv), mx = max(v, pv);
                ans.push_back(mp[{mn, mx}]);
            }
            swap(q, nq);
            nq.clear();
        }

        if (start[0] != target[0]) {
            return {-1};
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
