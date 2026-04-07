class Solution {
public:

    struct dsu {
        vector<int> parent;
        vector<int> sz;
        vector<int> dist; // dist[i] is the parity between node i and parent[i]

        dsu(int n) {
            parent.resize(n);
            sz.resize(n, 1);
            dist.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        pair<int, int> find_with_parity(int x) {
            if (parent[x] == x) {
                return {x, 0};
            }
            auto [root, root_parity] = find_with_parity(parent[x]);  
            parent[x] = root;
            dist[x] = dist[x] ^ root_parity; 
            return {parent[x], dist[x]};
        }

        bool union_with_weight(int u, int v, int w) {
            auto [root_u, p_u] = find_with_parity(u);
            auto [root_v, p_v] = find_with_parity(v);
            if (root_u == root_v) {
                return (p_u ^ p_v) == w;
            }
            if (sz[root_v] < sz[root_u]) {
                swap(root_v, root_u);
            }
            sz[root_v] += sz[root_u];
            parent[root_u] = root_v;
            dist[root_u] = p_u ^ w ^ p_v; 
            return true;
        }
    };

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        dsu ds(n);
        int ans = 0;
        for (auto &e: edges) {
            if (ds.union_with_weight(e[0], e[1], e[2])) {
                ans++;
            }
        }
        return ans;

    }
};
