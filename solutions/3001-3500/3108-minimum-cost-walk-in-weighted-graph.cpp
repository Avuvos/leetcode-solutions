class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e :edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        vector<int> node_to_comp(n, -1);
        auto dfs = [&](auto dfs, int u, int index) -> void {
            node_to_comp[u] = index;
            for (auto &[v, w]: g[u]) {
                if (node_to_comp[v] != -1) continue;
                dfs(dfs, v, index);
            }
        };
        
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (node_to_comp[i] == -1) {
                dfs(dfs, i, index);
                index++;
            }
        }

        vector<int> comp_and(index + 1, (1 << 28) - 1);
        for (auto &e: edges) {
            comp_and[node_to_comp[e[0]]] = comp_and[node_to_comp[e[0]]] & e[2];
        }
        
        vector<int> ans;
        for (auto& q: query) {
            int s = q[0], t = q[1];
            if (node_to_comp[s] != node_to_comp[t]) {
                ans.push_back(-1);
            } else {
                ans.push_back(comp_and[node_to_comp[s]]);
            }
        }
        return ans;
    }
};
